#include "movie.h"


int main() {
    Screen screens[NUM_SCREENS];
    if (!initializeSeats(screens)) {
        printf("ERROR INITIALIZING SEATS.\n");
        return SUCCESS;
    }

    BookingSystem booking_system;
    booking_system.count = 0;

    while (1) {
        if(booking_system.count>MAX_BOOKINGS-1){
            printf("BOOKING LIMIT EXCEEDED... :(");
            return FAILURE;
        }
        int choice;

        printf("Select an option:\n");
        printf("1. BOOK SEATS\n");
        printf("--------------------------\n");
        printf("2. VIEW ALL BOOKINGS\n");
        printf("--------------------------\n");
        printf("3. VIEW SEAT AVAILABILITY\n");
        printf("--------------------------\n");
        printf("4. EXIT\n");
        printf("--------------------------\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Ticket t1;

            printf("ENTER NAME: ");
            scanf("%s", t1.name);

            printf("ENTER PHONE NUMBER: ");
            scanf("%s", t1.phone_num);
            printf("--------------------------\n");

    int vip_size, gold_size, silver_size;
        while(1){
            printf("SELECT SCREEN [1, 2, or 3]: ");
            scanf("%d", &t1.screen);
            t1.screen -=1;

            if (t1.screen == 0 || t1.screen == 1 || t1.screen == 2 ) {
                vip_size = VIP_SEATS;
                gold_size = GOLD_SEATS;
                silver_size = SILVER_SEATS;
                break;
            }
            else{
                printf("UNABLE TO SELECT THE SCREEN, PLEASE SELECT VALID SCREEN NUMBER \n");
                while (getchar() != '\n');
            }
        }


            Screen *current_screen = &screens[t1.screen];

            while (1) {
                printSeats(current_screen, vip_size, gold_size, silver_size);
                int *selected_seats;
                int selected_size;
                while(1){
                printf("SELECT SEAT CATEGORY (1: VIP, 2: GOLD, 3: SILVER): ");
                scanf("%d", &t1.category);
                printf("\n");


                if (t1.category == VIP) {
                    selected_seats = current_screen->vip;
                    selected_size = vip_size;
                    break;
                } else if (t1.category == GOLD) {
                    selected_seats = current_screen->gold;
                    selected_size = gold_size;
                    break;
                } else if (t1.category == SILVER) {
                    selected_seats = current_screen->silver;
                    selected_size = silver_size;
                    break;
                }
                else{
                    printf("INVALID SEAT CATEGORY, PLEASE ENTER VALID INPUT\n");
                    while(getchar()!='\n');
                }
                }

                while(1){
                    printf("ENTER STARTING SEAT NUMBER (0 to %d): ", selected_size - 1);
                    scanf("%d", &t1.start_seat);
                    printf("\n");
                if(t1.start_seat>=0 && t1.start_seat<=(selected_size - 1)){
                    printf("Starting Seats selected!!\n");
                    break;
                }
                else{
                    printf("INVALID SEAT SELECTED,PLEASE ENTER VALID INPUT\n");
                    while(getchar()!='\n');
                }
               }

                printf("ENTER NUMBER OF SEATS : ");
                scanf("%d", &t1.num_seats);
                printf("\n");


                if (areSeatsAvailable(selected_seats, t1.start_seat, t1.num_seats, selected_size)) {
                    displaySelectedSeats(t1.start_seat, t1.num_seats);
                    if (confirmBooking()) {
                        blockSeats(selected_seats, t1.start_seat, t1.num_seats);

                        booking_system.tickets[booking_system.count++] = t1;
                        handlePayment(t1.category == VIP ? t1.num_seats : 0, t1.category == GOLD ? t1.num_seats : 0, t1.category == SILVER ? t1.num_seats : 0);
                        printf("BOOKING CONFIRMED.\n\n");
                        break;
                    } else {
                        printf("BOOKING CANCELLED.\n\n");
                        break;
                    }
                } else {
                    printf("SEATS NOT AVAILABLE, PLEASE CHOOSE A DIFFERENT RANGE.\n\n");
                }
            }

        } else if (choice == 2) {
            printBookings(&booking_system);
        } else if (choice == 3) {
            displayScreenStatus(screens);
        }
        else if (choice == 4) {
            printf("EXITING...\n");
            break;
        } else {
            printf("INVALID CHOICE. PLEASE TRY AGAIN.\n");
            printf("\n");
        }
    }

    return 0;
}
