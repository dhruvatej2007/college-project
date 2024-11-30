#include <stdio.h>

void welcome() {
      printf("\n************************************************************************");
    printf("\n                WELCOME TO DHRUVA SERVICE BILLING   ");
    printf("\n************************************************************************\n");
}

void input(int *numServices, int services[], int billingTypes[], float times[]) {
    printf("\nAvailable Services:");
    printf("\n 1. Amazon EC2 ");
    printf("\n 2. Amazon RDS ");
    printf("\n 3. Amazon IAM ");
    printf("\n 4. Amazon Aurora ");
    printf("\n 5. Amazon Business ");
    printf("\n 6. Amazon Twinmaker ");
    printf("\n 7. Amazon App Flow Cost ");
    printf("\n 8. Amazon App Stream ");
    printf("\n 9. Amazon API Gateway ");
    printf("\n10. Amazon Athena ");
    
    printf("\n\nHow many services are you using? ");
    scanf("%d", numServices);

    for (int i = 0; i < *numServices; i++) {
        printf("\nEnter your choice (1-10) for service %d: ", i + 1);
        scanf("%d", &services[i]);

        if (services[i] < 1 || services[i] > 10) {
            printf("Invalid service choice for service %d. Skipping.\n", i + 1);
            services[i] = 0; // Mark as invalid
            continue;
        }

        printf("Choose billing type for service %d: (1 for hourly, 2 for monthly): ", i + 1);
        scanf("%d", &billingTypes[i]);

        if (billingTypes[i] == 1) {
            printf("Enter the number of hours for service %d: ", i + 1);
        } else if (billingTypes[i] == 2) {
            printf("Enter the number of months for service %d: ", i + 1);
        } else {
            printf("Invalid billing type for service %d. Skipping.\n", i + 1);
            services[i] = 0; // Mark as invalid
            continue;
        }
        scanf("%f", &times[i]);
    }
}

float calculateBill(int service, int billingType, float time) {
    float rate = 0;

    switch (service) {
        case 1: rate = 0.104; break;
        case 2: rate = 0.018; break;
        case 3: rate = 0.10; break;
        case 4: rate = 0.10; break;
        case 5: rate = 0.233; break;
        case 6: rate = 0.503; break;
        case 7: rate = 0.001; break;
        case 8: rate = 3.50; break;
        case 9: rate = 3.50; break;
        case 10: rate = 0.49; break;
        default: return -1;  // Invalid service
    }

    if (billingType == 2) {  // Convert monthly rate to hourly equivalent
        rate *= 24 * 30;
    }

    return time * rate;
}

void output(int numServices, int services[], int billingTypes[], float times[]) {
    float totalBill = 0;

    printf("\n***************************************************************");
    for (int i = 0; i < numServices; i++) {
        if (services[i] == 0) {
            printf("\nService %d was skipped due to invalid input.", i + 1);
            continue;
        }

        float bill = calculateBill(services[i], billingTypes[i], times[i]);
        if (bill < 0) {
            printf("\nInvalid choice for service %d.", i + 1);
            continue;
        }

        printf("\nBill for service %d: $%.2f", i + 1, bill);
        totalBill += bill;
    }
      printf("\n***************************************************************\n");
    printf("\n         Total bill for all services: $%.2f", totalBill);
    printf("\n***************************************************************\n");
}

int main() {
    int numServices;
    int services[10];
    int billingTypes[10];
    float times[10];

    welcome();
    input(&numServices, services, billingTypes, times);
    output(numServices, services, billingTypes, times);

    return 0;
}
