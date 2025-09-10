#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Medicine med[100];
int count = 0;

void addMedicine() {
    printf("Enter Medicine ID: ");
    scanf("%d", &med[count].id);
    printf("Enter Medicine Name: ");
    scanf("%s", med[count].name);
    printf("Enter Quantity: ");
    scanf("%d", &med[count].quantity);
    printf("Enter Price: ");
    scanf("%f", &med[count].price);
    count++;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    printf("\n--- List of Medicines ---\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%d\t\t%.2f\n", med[i].id, med[i].name, med[i].quantity, med[i].price);
    }
}

void searchMedicine() {
    int id, found = 0;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (med[i].id == id) {
            printf("Medicine Found!\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", med[i].id, med[i].name, med[i].quantity, med[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void billMedicine() {
    int id, qty, found = 0;
    printf("Enter Medicine ID to bill: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (med[i].id == id) {
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if (qty <= med[i].quantity) {
                float total = qty * med[i].price;
                med[i].quantity -= qty;
                printf("Bill Amount: %.2f\n", total);
            } else {
                printf("Insufficient stock!\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void menu() {
    printf("\n--- Pharmacy Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Bill Medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                billMedicine();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}
