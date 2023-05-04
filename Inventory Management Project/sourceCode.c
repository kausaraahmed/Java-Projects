#include <stdio.h>
#include <string.h>

struct supplier
{
    char name[15];
    char division[10];
};
struct Inventory
{
    char name[15];
    int price;
    int quantity;
    struct supplier sup;
    char shelf[3];
    int dayStored;
    int demand;
};

// functions for complex logic
void listOfOverStock(struct Inventory product[]);
void productArea(struct Inventory product[]);
void productRestock(struct Inventory product[]);
void separator(void);
void welcomeNote(void);

int main()
{
    struct Inventory product[30];

    // taking input from external file
    FILE *input_file;
    input_file = fopen("database.txt", "r");
    char line[100];
    for (int i = 0; fgets(line, sizeof(line), input_file); i++)
    {
        sscanf(line, "%s %s %d %d %s %d %s %d", product[i].name, product[i].sup.name, &product[i].price, &product[i].quantity, product[i].shelf, &product[i].dayStored, product[i].sup.division, &product[i].demand);
    }
    fclose(input_file);
    welcomeNote();

    // logic 1
    separator();
    listOfOverStock(product);

    // logic 2
    separator();
    productArea(product);

    // logic 3
    separator();
    productRestock(product);

    separator();
}

// prints the list of the products which are stored more than 3 months
void listOfOverStock(struct Inventory product[])
{
    printf("\n\t\tOver-stock Products\n");
    printf("\t\t-------------------\n\n");
    printf("[Low demand products and stored more than 3 months.]\n\n");
    printf("Name\tShelf\tDays\n");
    printf("---------------------\n");
    for (int i = 0; i < 30; i++)
    {
        if (product[i].dayStored > 90 && product[i].demand <= 3)
        {
            printf("%s\t", product[i].name);
            printf(" %0.3s\t", product[i].shelf);
            printf("%d\n", product[i].dayStored);
        }
    }
}

// shows a stat of the products location in the country
void productArea(struct Inventory product[])
{
    printf("\n\t\t  Product zone\n");
    printf("\t\t  ------------\n");
    char divi[6][11] = {"Dhaka", "Khulna", "Rajshahi", "Rangpur", "Sylhet", "Chattogram"};
    float divCount[6] = {0};
    for (int j = 0; j < 6; j++)
    {
        printf("Suppliers from %s are:\n", divi[j]);
        int k = 1;
        for (int i = 0; i < 30; i++)
        {
            if (strcmp(product[i].sup.division, divi[j]) == 0)
            {
                printf("%d. %s\n", k++, product[i].sup.name);
                divCount[j]++;
            }
        }
        printf("\n");
    }

    printf("Statistics of product area:\n");
    printf("-------------------------------------------------\n");
    printf("%0.2f%% from Dhaka\t|  ", divCount[0] * 3.33);
    printf("%0.2f%% from Khulna\n", divCount[1] * 3.33);
    printf("-------------------------------------------------\n");
    printf("%0.2f%% from Rajshahi\t|  ", divCount[2] * 3.33);
    printf("%0.2f%% from Rangpur\n", divCount[3] * 3.33);
    printf("-------------------------------------------------\n");
    printf("%0.2f%% from Sylhet\t|  ", divCount[4] * 3.33);
    printf("%0.2f%% from Chattogram\n", divCount[5] * 3.33);
    printf("-------------------------------------------------\n");
}

void productRestock(struct Inventory product[])
{
    printf("\n\t\tLow stock products\n");
    printf("\t\t------------------\n");
    printf("[A bill to order the high demand and low stock products.]\n");
    printf("\nName\tquantity\n");
    printf("-----------------\n");
    for (int i = 0; i < 30; i++)
    {
        if (product[i].quantity < 50)
        {
            printf("%s\t", product[i].name);
            printf("   %d\n", product[i].quantity);
        }
    }
    int stock, total = 0, sl = 0;
    printf("\nMinimum order size 80");
    printf("\nRe-stock item to unit: ");
    scanf("%d", &stock);
    if (stock >= 80)
    {
        printf("\nBill for re-stocking products\n");
        printf("-----------------------------\n");
        printf("\nSl\tName\tQuant\tPrice\ttotal\n");
        printf("-------------------------------------\n");
        for (int i = 0; i < 30; i++)
        {
            if (product[i].quantity < 50 && product[i].demand > 6)
            {
                printf("%d\t", sl + 1);
                printf("%s\t", product[i].name);
                printf("  %d\t", stock - product[i].quantity);
                printf("%d\t", product[i].price);
                int price = (stock - product[i].quantity) * product[i].price;
                printf(" %d\n", price);
                total += price;
                sl++;
            }
        }
        printf("-------------------------------------\n");
        printf("\t\t\t  Total: %d\n\n", total);
    }
    else
        printf("\nError!!! order size must be greater than 80 units.\n\n");
}

// for separating the logics
void separator(void)
{
    printf("\n=================================================\n");
}

void welcomeNote(void)
{
    printf("\n=================================================\n");
    printf("\n\t\tWelcome to Stockify\n");
}