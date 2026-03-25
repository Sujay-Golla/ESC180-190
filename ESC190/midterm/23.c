typedef struct business {
    int phone_number[10];
    char *name;
} business;

void read_numbers(const char *filename, business **b, int *size){
    FILE *fp = fopen(filename, "r");
    char buffer[256];
    *size = atoi(fgets(buffer, sizeof(buffer), fp));
    *b = (business*)malloc(sizeof(business) * (*size));
    for (int i = 0; i < *size; i++){
        // reading a line with undefined number of characters, so we need to use dynamic memory allocation
        // Format: XXX-XXX-XXXX\tName\n
        char *line = NULL;
        size_t len = 0;
        getline(&line, &len, fp);
        char *token = strtok(line, "\t");
        for (int j = 0; j < 10; j++){
            (*b)[i].phone_number[j] = token[j + (j / 3)];
        }
        (*b)[i].name = strdup(strtok(NULL, "\n"));
    }
}

int main() {
    // Write C code here
    
}