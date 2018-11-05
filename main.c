/*
 * A once in a lifetime event will take place on September 26th, 2020. Several world-class artists will hold a concert
 * for the Benefit of Mr. G. Sir Paul McCartney, Sting, Phil Collins, Mark Knopfler, Robert Plant, Jimmy Page, Blondie,
 * Eric Clapton, Ringo Starr, Brian May, Bob Dylan, The Rolling Stones, Annie Lennox, Status Quo, Roger Waters, Carlos
 * Santana, Joan Jett, Toto, among others, have confirmed their presence in the show. This is going to be an epic rock
 * show! Mr. G. is delighted because all those artists are going to sing “Happy Birthday” to him. Sir Paul has promised
 * to sing The Beatles’ “You Say it’s Your Birthday”.
 *
 * This program is design to control and register the tickets sales of this event.
 *
 * Author: Soraya Maqueda
 * Date: 03.10.2018
 * Contact: soraya_maqueda@hotmail.com
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//ARENA RECORDS
struct sales{

    char first_name[50];
    char last_name[50];
    char payment_method;
    char zone[20];
    struct left_wing left;
    struct middle center;
    struct right_wing right;

}ticket[400][210][13];

//Records for Left Wing Zones' Tickets
struct left_wing{
    char first_name[50];
    char last_name[50];
    char payment_method;
    bool available;
}sky_left[400][50][3];

//Records for Center Zones' Tickets
struct middle{
    char first_name[50];
    char last_name[50];
    char payment_method;
    bool available;
}center[400][100][7];

//Records for Right Wing Zones' Tickets
struct right_wing{
    char first_name[50];
    char last_name[50];
    char payment_method;
    bool available;
}sky_right[400][50][3];


int sale() {

    //Prices
    printf("\n\t\t\t\t\t\tHAPPY BIRTHDAY MR. G!\n");
    printf("The Travelling Wilburys Memorial Park has been divided into three sections, each with different zones for\n");
    printf("the better enjoyment of the event. The price of your ticket will depend on which zone and section you choose.\n");
    printf("NOTE ALL PRICES ARE STATED IN USD\n");
    printf("NOTE: There is a hallway between zones.\n");
    printf("\t\t\t\tLEFT WING\t\t\t\tCENTER\t\t\t\tRIGHT WING\n");

    //Sky Zone Prices
    printf("LEFT AND RIGHT WING ZONES AND PRICES\n");
    printf("Note: The zones are listed from nearest to farthest from the stage\n");

    printf("SKY BLUE ZONE:  $50 USD\n");
    printf("Rows: 1-100\n");
    printf("\n\n");

    printf("NAVY BLUE ZONE: $35 UDS\n");
    printf("Rows: 101-300\n");
    printf("\n\n");

    printf("DEEP BLUE ZONE: $20 USD\n");
    printf("Rows: 301-400\n");
    printf("\n\n");
    printf("\n\n");

    //Center Prices
    printf("CENTER ZONES AND PRICES\n");
    printf("Note: The zones are listed from nearest to farthest from the stage\n");

    printf("VIP ZONE: $100 USD\n");
    printf("Rows: 1-5\n");
    printf("\n\n");

    printf("PLATINUM ZONE: $85 USD\n");
    printf("Rows: 6-10\n");
    printf("\n\n");

    printf("GOLDEN ZONE: $70 USD\n");
    printf("Rows: 11-50\n");
    printf("\n\n");

    printf("SILVER ZONE: $55 USD\n");
    printf("Rows: 51-100\n");
    printf("\n\n");

    printf("GREEN ZONE: $45 USD\n");
    printf("Rows: 101-250\n");
    printf("\n\n");

    printf("YELLOW ZONE: $40 USD\n");
    printf("Rows: 251-350\n");
    printf("\n\n");

    printf("RED ZONE: $30 USD\n");
    printf("Rows: 351-400\n");
    printf("\n\n");

    //Zone Selection
    char zone[20];

    //Nested structure for Left Wing Zones' Tickets
    struct sales left;
    printf("'LEFT WING ZONE' tickets.\n");
    printf("Type Left.\n");

    //Nested structure for Left Wing Zones' Tickets
    struct sales center;
    printf("'CENTER ZONE' tickets.\n");
    printf("Type Center.\n");

    //Nested structure for Left Wing Zones' Tickets
    struct sales right;
    printf("'RIGHT WING ZONE' tickets.\n");
    printf("Type Right.\n");

    printf("Zone: ");
    fflush(stdin);
    fgets(zone, strlen(zone), stdin);
    strcpy(ticket[400][210][13].zone, zone);

    //Seat Assignment Variables
    int row;
    int seat;
    int section;

    switch (zone){
        //Left Wing Tickets
        case 'Left':

            //Name
            printf("Enter your first name: \n");
            scanf("%s", &left.left.first_name[50]);
            strcpy(ticket[400][210][13].first_name[50], left.left.first_name[50]);
            printf("Enter your last name: \n");
            scanf("%s", &left.left.last_name[50]);
            strcpy(ticket[400][210][13].last_name[50], left.left.last_name[50]);

            //Payment Method
            printf("\t\t\t\tAcceptable payment methods\n");
            printf("Visa (V)\n");
            printf("MasterCard (M)\n");
            printf("American Express (A)\n");
            scanf("%c", &left.left.payment_method);
            strcpy(ticket[400][210][13].payment_method, left.left.payment_method);

            //Selecting Section
            printf("1 SKY BLUE ZONE:  $50 USD\n");
            printf("Rows: 1-100\n");
            printf("\n\n");

            printf("2 NAVY BLUE ZONE: $35 UDS\n");
            printf("Rows: 101-300\n");
            printf("\n\n");

            printf("3 DEEP BLUE ZONE: $20 USD\n");
            printf("Rows: 301-400\n");
            printf("\n\n");

            printf("Choose a section: \n");
            scanf("%i", &section);

            printf("Choose a row: \n");
            scanf("%i", &row);


            printf("Choose a seat: \n");
            scanf("%i", &seat);

            //Generating Ticket
            sky_left[row][seat][section];

            //Verification of availability
            for (int i = 0; i < row; i++){
                for (int k = i + 1; k < row; k++){
                    for (int j = k + 1; j < row; j++){
                        if (strlen(sky_left[row][seat][section].payment_method) != " "){
                            sky_left[row][seat][section].available = false;
                            printf("This seat is occupied by %s %s. Please select another one.\n", sky_left[400][50][3].first_name, sky_left[400][50][3].last_name);
                        }
                    }
                }
            }

            //Payment Calculation
            int totalLeft;

            if (row <= 0 || row >= 99 && seat <= 0 || seat >= 5099){
                totalLeft = 50;
            } else{
                if (row <= 100 || row >= 299 && seat <= 5100 || seat >= 15299){
                    totalLeft = 35;
                } else{
                    if (row <= 300 || row >= 399 && seat <= 15300 || seat >= 20399){
                        totalLeft= 20;
                    }
                }
            }

            //Generating Voucher
            printf("\t\t\t\tVoucher\n");
            printf("Name: %s %s", left.left.first_name[50], left.left.last_name[50]);
            printf("Zone: Left Wing\n");
            printf("Seat: %i\n", seat);
            printf("Row: %i\n", row);
            printf("Total: $%i\n", totalLeft);
            printf("Payment Method: %c\n", sky_left[row][seat][section].payment_method);

            break;

        //Center Tickets
        case 'Center':

            //Name
            printf("Enter your first name: \n");
            scanf("%s", &center.center.first_name[50]);
            strcpy(ticket[400][210][13].first_name[50], center.center.first_name[50]);
            printf("Enter your last name: \n");
            scanf("%s", &center.center.last_name[50]);
            strcpy(ticket[400][210][13].last_name[50], center.center.last_name[50]);

            //Payment Method
            printf("\t\t\t\tAcceptable payment methods\n");
            printf("Visa (V)\n");
            printf("MasterCard (M)\n");
            printf("American Express (A)\n");
            scanf("%c", &center.center.payment_method);
            strcpy(ticket[400][210][13].payment_method, center.center.payment_method);

            //Selecting Section
            printf("1 VIP ZONE: $100 USD\n");
            printf("Rows: 1-5\n");
            printf("\n\n");

            printf("2 PLATINUM ZONE: $85 USD\n");
            printf("Rows: 6-10\n");
            printf("\n\n");

            printf("3 GOLDEN ZONE: $70 USD\n");
            printf("Rows: 11-50\n");
            printf("\n\n");

            printf("4 SILVER ZONE: $55 USD\n");
            printf("Rows: 51-100\n");
            printf("\n\n");

            printf("5 GREEN ZONE: $45 USD\n");
            printf("Rows: 101-250\n");
            printf("\n\n");

            printf("6 YELLOW ZONE: $40 USD\n");
            printf("Rows: 251-350\n");
            printf("\n\n");

            printf("7 RED ZONE: $30 USD\n");
            printf("Rows: 351-400\n");
            printf("\n\n");

            printf("Choose a section: \n");
            scanf("%i", &section);

            printf("Choose a row: \n");
            scanf("%i", &row);


            printf("Choose a seat: \n");
            scanf("%i", &seat);

            //Generating Ticket
            center[row][seat][section];

            //Verification of availability
            for (int i = 0; i < row; i++){
                for (int k = i + 1; k < row; k++){
                    for (int j = k + 1; j < row; j++){
                        if (strlen(center[row][seat][section].payment_method) != " "){
                            center[row][seat][section].available = false;
                            printf("This seat is occupied by %s %s. Please select another one.\n", center[400][100][7].first_name, center[400][100][7].last_name);
                        }
                    }
                }
            }

            //Payment Calculation
            int totalCenter;

            if (row <= 0 || row >= 4 && seat <= 0 || seat >= 505){
                totalCenter = 100;
            } else{
                if (row <= 5 || row >= 9 && seat <= 505 || seat >= 1009){
                    totalCenter = 85;
                } else{
                    if (row <= 10 || row >= 49 && seat <= 1010 || seat >= 5049){
                        totalCenter = 70;
                    } else{
                        if (row <= 50 || row >= 99 && seat <= 5050 || seat >= 10099){
                            totalCenter = 55;
                        } else{
                            if (row <= 100 || row >= 249 && seat <= 10100 || seat >= 25249){
                                totalCenter = 45;
                            } else{
                                if (row <= 250 || row >= 349 && seat <= 25250 || seat >= 35349){
                                    totalCenter = 40;
                                } else{
                                    if (row <= 350 || row >= 399){
                                        totalCenter = 30;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            //Generating Voucher
            printf("\t\t\t\tVoucher\n");
            printf("Name: %s %s", center.center.first_name[50], center.center.last_name[50]);
            printf("Zone: Center\n");
            printf("Seat: %i\n", seat);
            printf("Row: %i\n", row);
            printf("Total: $%i\n", totalCenter);
            printf("Payment Method: %c\n", center[row][seat][section].payment_method);

            break;

        case 'Right':

            //Name
            printf("Enter your first name: \n");
            scanf("%s", &right.right.first_name[50]);
            strcpy(ticket[400][210][13].first_name[50], right.right.first_name[50]);
            printf("Enter your last name: \n");
            scanf("%s", &left.right.last_name[50]);
            strcpy(ticket[400][210][13].last_name[50], right.right.last_name[50]);

            //Payment Method
            printf("\t\t\t\tAcceptable payment methods\n");
            printf("Visa (V)\n");
            printf("MasterCard (M)\n");
            printf("American Express (A)\n");
            scanf("%c", &right.right.payment_method);
            strcpy(ticket[400][210][13].payment_method, right.right.payment_method);

            //Selecting Section
            printf("1 SKY BLUE ZONE:  $50 USD\n");
            printf("Rows: 1-100\n");
            printf("\n\n");

            printf("2 NAVY BLUE ZONE: $35 UDS\n");
            printf("Rows: 101-300\n");
            printf("\n\n");

            printf("3 DEEP BLUE ZONE: $20 USD\n");
            printf("Rows: 301-400\n");
            printf("\n\n");

            printf("Choose a section: \n");
            scanf("%i", &section);

            printf("Choose a row: \n");
            scanf("%i", &row);


            printf("Choose a seat: \n");
            scanf("%i", &seat);

            //Generating Ticket
            sky_right[row][seat][section];

            //Verification of availability
            for (int i = 0; i < row; i++){
                for (int k = i + 1; k < row; k++){
                    for (int j = k + 1; j < row; j++){
                        if (strlen(sky_right[row][seat][section].payment_method) != " " && strlen(sky_right[row][seat][section].payment_method) != "\0"){
                            sky_right[row][seat][section].available = false;
                            printf("This seat is occupied by %s %s. Please select another one.\n", sky_right[400][50][3].first_name, sky_right[400][50][3].last_name);
                        }
                    }
                }
            }

            //Payment Calculation
            int totalRight;

            if (row <= 0 || row >= 99 && seat <= 0 || seat >= 5099){
                totalRight = 50;
            } else{
                if (row <= 100 || row >= 299 && seat <= 5100 || seat >= 15299){
                    totalRight = 35;
                } else{
                    if (row <= 300 || row >= 399 && seat <= 15300 || seat >= 20399){
                        totalRight= 20;
                    }
                }
            }

            //Generating Voucher
            printf("\t\t\t\tVoucher\n");
            printf("Name: %s %s", right.right.first_name[50], right.right.last_name[50]);
            printf("Zone: Right Wing\n");
            printf("Seat: %i\n", seat);
            printf("Row: %i\n", row);
            printf("Total: $%i\n", totalRight);
            printf("Payment Method: %c\n", sky_right[row][seat][section].payment_method);

            break;
        default:
            printf("Option not valid.");
    }

}

int main() {
    int sold = 0;
    char firstName[50];
    char lastName[50];
    char payment;
    char zone[20];
    int line;
    int column;
    int total;

    //File to store data
    FILE *MrGSalesTicket;
    MrGSalesTicket = fopen("Mr. G Birthday Party Sales Ticket.txt", "w");

    //Welcome message for the user
    printf("\t\t\t\t\t\tHAPPY BIRTHDAY MR. G!\n");
    printf("Are you ready to party to the beat of good rock'n'roll music whilst we celebrate Mr. G's Birthday?\n");
    printf("Sir Paul McCartney, Jimmy Page, Ringo Star, The Rolling Stones, Carlos Santana, and many others have\n");
    printf("confirmed their attendance to this once in a lifetime epic event! Now the question is, are you going to\n");
    printf("join us?\n");
    printf("The date: September 26,2020\n");
    printf("The place: The Travelling Wilburys Memorial Park\n");
    printf("Get your tickets now!\n");
    printf("\n\n");

    //Menu
    char option;
    printf("Enter 'A' for buying a ticket.\n");
    printf("Enter 'B' for saving a purchase.\n");
    printf("Enter 'C' for viewing our sales reports.\n");
    printf("Enter 'E' to exit the system.\n");
    printf("Option: ");
    fflush(stdin);
    fgets(option, sizeof(option), stdin);

    switch (option){
        case 'A':

            //Function for purchasing a ticket.
            sale();

            //Saving to file
            fwrite(MrGSalesTicket, sizeof(ticket[400][210][13]), sizeof(ticket[400][210][13]), MrGSalesTicket);

            break;

        //Introducing Sale
        case 'B':

            //Name
            printf("Enter First Name: \n");
            fflush(stdin);
            fgets(firstName, sizeof(firstName), stdin);
            fwrite(MrGSalesTicket, sizeof(firstName), 50, MrGSalesTicket);
            printf("Enter Last Name: \n");
            fflush(stdin);
            fgets(lastName, sizeof(lastName), stdin);
            fwrite(MrGSalesTicket, sizeof(lastName), 50, MrGSalesTicket);

            //Payment Method
            printf("For this event we accept Visa (V), MasterCard (M) and American Express (A) as possible payment methods.\n");
            printf("Introduce the Payment Method: \n");
            fflush(stdin);
            fgets(payment, sizeof(payment), stdin);
            fwrite(MrGSalesTicket, sizeof(payment), 1, MrGSalesTicket);

            //Zone
            printf("'Left' for Left Wing Tickets.\n");
            printf("'Center' for Center Zone Tickets.\n");
            printf("'Right' for Right Wing Tickets.\n");
            printf("Introduce the zone: \n");
            fflush(stdin);
            fgets(zone, sizeof(zone), stdin);
            fwrite(MrGSalesTicket, sizeof(zone), 20, MrGSalesTicket);

            //Seat
            printf("Introduce Seat: \n");
            scanf("%i", &column);
            fwrite(MrGSalesTicket, sizeof(column), sizeof(column), MrGSalesTicket);
            printf("Introduce Row: \n");
            scanf("%i", &line);
            fwrite(MrGSalesTicket, sizeof(line), sizeof(line), MrGSalesTicket);

            //Total Payed
            printf("introduced Total Amount Payed: \n");
            scanf("%i", &total);
            fwrite(MrGSalesTicket, sizeof(total), sizeof(total), MrGSalesTicket);

            break;

        //Sales Report
        case 'C':

            //Total Tickets Sold
            if (sky_left[400][50][3].available == false && sky_right[400][50][3].available == false && center[400][100][7].available == false){
                sold++;
            }

            printf("The total sold tickets are: %i\n", sold);
            printf("I bet there's still a ticket with your name on it.\n");
            printf("What are you waiting for?!\n");
            printf("\n\n");

            ///Total Tickets per Zone

            //Left Wing Sales
            int leftSales = 0;

            if (sky_left[400][50][3].available == false){
                leftSales++;
            }

            printf("Left Wing Sold Tickets: %i\n", leftSales);

            //Center Sales
            int centerSales = 0;

            if (center[400][100][7].available == false){
                centerSales++;
            }

            printf("Center Zone Sold Tickets: %i\n", centerSales);

            //Right Wing Sales
            int rightSales = 0;

            if (sky_right[400][50][3].available == false){
                rightSales++;
            }

            printf("Right Wing Sold Tickets: %i\n", rightSales);

            printf("\n\n");

            //Total Income
            //IDK HOW TO DO THIS!

            ///Total Income per Zone
            //MAY BE COUNTERS WITH POINTERS BUT IDK HOW!

            //Occupation Rate
            double occupation;
            occupation = (leftSales / 20000) + (centerSales / 40000) + (rightSales / 20000);

            printf("Total Occupation Rate: %lf\n", occupation);
            printf("\n\n");

            ///Occupation Rate per Zone

            //Left Wing Occupation Rate
            double occupationLeft;
            occupationLeft = leftSales / 20000;
            printf("Total Left Wing Occupation Rate: %lf\n", occupationLeft);
            printf("\n\n");

            //Center Zone Occupation Rate
            double occupationCenter;
            occupationCenter = centerSales / 40000;
            printf("Total Center Zone Occupation Rate: %lf\n", occupationCenter);
            printf("\n\n");

            //Right Wing Occupation Rate
            double occupationRight;
            occupationRight = rightSales / 20000;
            printf("Total Right Wing Occupation Rate: %lf\n", occupationRight);
            printf("\n\n");

            break;

        //Exit
        case 'E':

            //Message for when the user chooses to leave the system.
            printf("\nYou are now exiting our system.\n");

            break;

       //Not Valid Option Introduced
       default:
            printf("Option not valid.");
    }

    //Closing File
    fclose(MrGSalesTicket);

    return 0;
}