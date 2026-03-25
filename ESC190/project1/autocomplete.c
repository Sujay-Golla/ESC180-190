#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autocomplete.h"

int compare(const void *a, const void *b)
{
    return strcmp(((struct term*)a)->term, ((struct term*)b)->term);
}

int compare_weight(const void *a, const void *b)
{
    return ((struct term*)b)->weight - ((struct term*)a)->weight;
}

void read_in_terms(struct term **terms, int *pnterms, char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[300];
    fgets(line, sizeof(line), f);
    int nterms = atoi(line);
    *pnterms = nterms;
    *terms = (struct term *)malloc(nterms * sizeof(struct term));
    for (int i = 0; i < nterms; i++) {
        fgets(line, sizeof(line), f);
        char *weight = strtok(line, "\t");
        (*terms)[i].weight = atoi(weight);
        char *term = strtok(NULL, "\n");
        strcpy((*terms)[i].term, term);
    }
    fclose(f);

    qsort(*terms, nterms, sizeof(struct term), compare);
}
int lowest_match(struct term *terms, int nterms, char *substr)
{
    int mid;
    int low = 0;
    int high = nterms - 1;
    int res = -1;
    int sz = strlen(substr);
    
    while (low <= high) {
        mid = low + (high - low) / 2;

        if (strncmp(terms[mid].term, substr, sz) == 0){
            res = mid;
            high = mid - 1;
        } else if (strncmp(terms[mid].term, substr, sz) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}
int highest_match(struct term *terms, int nterms, char *substr)
{
    int mid;
    int low = 0;
    int high = nterms - 1;
    int res = -1;
    int sz = strlen(substr);
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        
        if (strncmp(terms[mid].term, substr, sz) == 0){
            res = mid;
            low = mid + 1;
        } else if (strncmp(terms[mid].term, substr, sz) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr)
{
    int low = lowest_match(terms, nterms, substr);
    int high = highest_match(terms, nterms, substr);
    *answer = (struct term *)malloc((high - low + 1) * sizeof(struct term));
    *n_answer = high - low + 1;

    for (int i = low; i <= high; i++) {
        struct term temp;
        strcpy(temp.term, terms[i].term);
        temp.weight = terms[i].weight;
        (*answer)[i - low] = temp;
    }

    qsort(*answer, *n_answer, sizeof(struct term), compare_weight);
}