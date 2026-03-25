#include <stdio.h>
#include <stdlib.h>

double my_atof(const char *str) {
    double result = 0.0;
    int sign = 1;
    int i = 0;

    
    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }
    
    
    double frac = 0.0;
    if (str[i] == '.') {
        i++;
        double divisor = 10.0;
        while (str[i] >= '0' && str[i] <= '9') {
            frac += (str[i] - '0') / divisor;
            divisor *= 10.0;
            i++;
        }
    }
    return sign * (result + frac);
}

double my_atof_sum(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0.0;
    }

    double sum = 0.0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        sum += my_atof(line);
    }
    fclose(file);
    return sum;
}

int main() {
    printf("Sum: %f\n", my_atof_sum("atof_test.txt"));
}
