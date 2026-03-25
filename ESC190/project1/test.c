int main()
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");

    // for (int i = 5; i < 20; i++) {
    //     printf("%f\t%s\n", terms[i].weight, terms[i].term);
    // }

    // int low = lowest_match(terms, nterms, "Aal");
    // int high = highest_match(terms, nterms, "Aal");
    // printf("Low: %d, High: %d\n", low, high);
    // for (int i = low; i <= high; i++) {
    //     printf("%f\t%s\n", terms[i].weight, terms[i].term);
    // }

    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Aal");
    for (int i = 0; i < n_answer; i++) {
        printf("%f\t%s\n", answer[i].weight, answer[i].term);
    }
}