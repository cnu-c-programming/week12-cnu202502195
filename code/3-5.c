#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        return 0;
    }

    int num;
    int sum=0;

    char buffer[256];

    while(!feof(fp)) {
        if(fscanf(fp, "%d", &num) == 1) {
            sum += num;
        } 
        else {
            fscanf(fp, "%s", buffer);
            fprintf(stderr, "invalid: %s\n", buffer);
        }
    }
    
    printf("sum: %d\n", sum);
    fcose(fp);
    return 0;
}
