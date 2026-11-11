#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[20];
    int address;
};

int main() {
    struct Symbol s[10];
    int n = 0, choice, i, found;
    char search[20];

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (n == 10) {
                    printf("Symbol Table Full!\n");
                    break;
                }

                printf("Enter name, type and address: ");
                scanf("%19s %19s %d", s[n].name, s[n].type, &s[n].address);

                n++;
                printf("Inserted Successfully!\n");
                break;

            case 2:
                printf("\nName\tType\tAddress\n");

                for (i = 0; i < n; i++) {
                    printf("%s\t%s\t%d\n",
                           s[i].name, s[i].type, s[i].address);
                }
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%19s", search);

                found = 0;

                for (i = 0; i < n; i++) {
                    if (strcmp(search, s[i].name) == 0) {
                        printf("Symbol Found!\n");
                        printf("Name: %s\nType: %s\nAddress: %d\n",
                               s[i].name, s[i].type, s[i].address);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Symbol Not Found!\n");

                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
