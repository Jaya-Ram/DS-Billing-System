#include <stdio.h>

struct MenuItem
{
    char name[50];
    float price;
};

int main()
{
    struct MenuItem menu[10] = {
        {"1. Coffee\t\t", 20.00},
        {"2. Tea\t\t", 10.00},
        {"3. Sandwich\t\t", 50.00},
        {"4. Burger\t\t", 80.00},
        {"5. Salad\t\t", 40.00},
        {"6. Cake\t\t", 40.00},
        {"7. Muffin\t\t", 100.0},
        {"8. Soda\t\t", 20.00},
        {"9. Juice\t\t", 40.00},
        {"10. Fries\t\t", 120.00}};

    int order[10] = {0};
    int quantity;
    float total = 0;
    char response;

    do
    {
        printf("\n\t\t\tWelcome to Cafeteria\t\n");
        printf("\nHere's my menu:\n\n");

        for (int i = 0; i < 10; i++)
        {
            printf("%s - RS:%.2f\n", menu[i].name, menu[i].price);
        }

        printf("Enter the item number to order (1-10): ");
        int itemNumber;
        scanf("%d", &itemNumber);

        if (itemNumber < 1 || itemNumber > 10)
        {
            printf("Invalid item number. Please enter a number between 1 and 10.\n");
            continue;
        }

        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        order[itemNumber - 1] += quantity;

        printf("Do you need anything else? (y/n): ");
        scanf(" %c", &response);

    } while (response == 'y');

    printf("Do you want to print the bill? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y')
    {
        printf("\n-- Order --\n");

        for (int i = 0; i < 10; i++)
        {
            if (order[i] > 0)
            {
                printf("%d. %s: %d x Rs:.%.2f\n", i + 1, menu[i].name, order[i], menu[i].price);
                total += order[i] * menu[i].price;
            }
        }

        printf("\nTotal amount: %.2f Rs\n", total);

        // Payment method selection
        printf("\nPlease choose your payment method:\n");
        printf("1. Cash\n");
        printf("2. Online Payment\n");
        int paymentMethod;
        scanf("%d", &paymentMethod);

        // Handle cash payment
        if (paymentMethod == 1)
        {
            printf("Pay to waiter!\n");
        }
        // Keep your online payment logic as is
        else if (paymentMethod == 2)
        {

            printf("Payment Link:https://example.com/payment?amount");
        }
        // Handle invalid input
        else
        {
            printf("Invalid payment method selection. Please choose 1 for cash or 2 for online payment.\n");
        }
    }

    return 0; // Add this line to indicate successful program execution
}
