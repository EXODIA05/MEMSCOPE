#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int choice;
    int a;
    double b;
    char first;
    int aa;

   
    puts("ENTER THE INTEGER");
    if (scanf("%d", &a) != 1)
    {
        puts("Invalid integer.");
        return 1;
    }

    puts("ENTER THE DOUBLE");
    if (scanf("%lf", &b) != 1)
    {
        puts("Invalid double.");
        return 1;
    }

    puts("ENTER THE CHARACTER");
    if (scanf(" %c", &first) != 1)
    {
        puts("Invalid character.");
        return 1;
    }

    puts("ENTER THE SIZE OF ARRAY");
    if (scanf("%d", &aa) != 1 || aa <= 0)
    {
        puts("INVALID ARRAY SIZE");
        return 1;
    }
    

    
    int *arr = calloc((size_t)aa, sizeof(int));

    if (arr == NULL)
    {
        puts("Memory allocation failed.");
        return 1;
    }
    
    puts("Enter the array elements:");

    for (int i = 0; i < aa; i++)
    {
       printf("arr[%d]: ", i);

       if (scanf("%d", &arr[i]) != 1)
       {
		   puts("Invalid input.");
           free(arr);
           return 1;
       }
     }

    
    while (1)
    {
        puts("\n========== MEMSCOPE ==========");
        puts("[1] Variable Inspection");
        puts("[2] Array Memory Inspection");
        puts("[3] Pointer Inspection");
        puts("[4] Memory Modification");
        puts("[0] Exit");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            puts("Invalid input.");
            break;
        }

        switch (choice)
        {
            
            case 1:
            {
                puts("\n--- VARIABLE INSPECTION ---");

                printf("Integer value: %d\n", a);
                printf("Size: %zu bytes\n", sizeof(a));
                printf("Address: %p\n", (void *)&a);

                printf("\nDouble value: %.4f\n", b);
                printf("Size: %zu bytes\n", sizeof(b));
                printf("Address: %p\n", (void *)&b);

                printf("\nCharacter value: %c\n", first);
                printf("Size: %zu bytes\n", sizeof(first));
                printf("Address: %p\n", (void *)&first);

                break;
            }

            
            case 2:
            {
                puts("\n--- ARRAY MEMORY INSPECTION ---");

                printf("Array base address: %p\n", (void *)arr);
                printf("Total allocated size: %zu bytes\n",
                       (size_t)aa * sizeof(int));

                for (int i = 0; i < aa; i++)
                {
                    printf("Index: %d | Value: %d | Address: %p\n",
                           i, arr[i], (void *)&arr[i]);
                }
                

                break;
            }

            
            case 3:
            {
                puts("\n--- POINTER INSPECTION ---");

                int *ptr = arr;

                printf("Pointer's own address: %p\n", (void *)&ptr);
                printf("Address stored in pointer: %p\n", (void *)ptr);
                printf("Value at pointed address: %d\n", *ptr);

                for (int i = 0; i < aa; i++)
                {
                    printf("Index: %d | Address: %p | Dereferenced value: %d\n",
                           i, (void *)(ptr + i), *(ptr + i));
                }

                break;
            }

            
            case 4:
            {
                int index;
                int num;

                puts("\n--- MEMORY MODIFICATION ---");
                printf("Enter the index (0 to %d): ", aa - 1);

                if (scanf("%d", &index) != 1)
                {
                    puts("Invalid index input.");
                    free(arr);
                    return 1;
                }

                if (index < 0 || index >= aa)
                {
                    puts("Invalid index.");
                    break;
                }

                printf("Enter the new value: ");

                if (scanf("%d", &num) != 1)
                {
                    puts("Invalid value.");
                    free(arr);
                    return 1;
                }

                printf("Original value: %d\n", arr[index]);

                int *ptr = &arr[index];
                *ptr = num;

                printf("Modified value through pointer: %d\n", *ptr);
                printf("Updated array element: %d\n", arr[index]);
                printf("Element address: %p\n", (void *)ptr);

                break;
            }

         
            case 0:
            {
                puts("Exiting MemScope.");
                free(arr);
                return 0;
            }

            
            default:
            {
                puts("Invalid choice. Select 0 to 4.");
                break;
            }
        }
    }

    free(arr);
    return 0;
}
