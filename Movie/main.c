#include "movie.h"


int main() {
    Screen screens[NUM_SCREENS];
    if (!initializeSeats(screens)) {
        printf("Error initializing seats.\n");
        return 1;
    }

    BookingSystem booking_system;
    booking_system.count = 0;

    while (1) {
        int choice;

        printf("Select an option:\n");
        printf("1. Book Seats\n");
        printf("2. View All Bookings\n");
        printf("3. View Seat Availability\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else if (choice == 1) {
            Ticket t1;

            printf("Enter Name: ");
            scanf("%s", t1.name);

            printf("Enter Phone Number: ");
            scanf("%s", t1.phone_num);

    int vip_size, gold_size, silver_size;
        while(1){
            printf("Select Screen (1, 2, or 3): ");
            scanf("%d", &t1.screen);
            t1.screen -=1;

            if (t1.screen == 0 || t1.screen == 1 || t1.screen == 2 ) {
                vip_size = VIP_SEATS;
                gold_size = GOLD_SEATS;
                silver_size = SILVER_SEATS;
                break;
            }
            else{
                printf("Unable to select the screen, Please select valid screen number \n");
                while (getchar() != '\n');
            }
        }


            Screen *current_screen = &screens[t1.screen];

            while (1) {
                printSeats(current_screen, vip_size, gold_size, silver_size);
                int *selected_seats;
                int selected_size;
                while(1){
                printf("Select seat category (1: VIP, 2: GOLD, 3: SILVER): ");
                scanf("%d", &t1.category);



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
                    printf("Invalid seat category, Please select the valid input\n");
                    while(getchar()!='\n');
                }
                }
                //(isdigit(t1.start_seat))
                while(1){
                    printf("Enter starting seat number (0 to %d): ", selected_size - 1);
                scanf("%d", &t1.start_seat);
                if(t1.start_seat>=0 && t1.start_seat<=(selected_size - 1)){
                    printf("Starting Seats selected!!\n");
                    break;
                }
                else{
                    printf("Invalid Seat selected, Please enter valid input\n");
                    while(getchar()!='\n');
                }
               }

                printf("Enter number of seats: ");
                scanf("%d", &t1.num_seats);

                if (areSeatsAvailable(selected_seats, t1.start_seat, t1.num_seats, selected_size)) {
                    displaySelectedSeats(t1.start_seat, t1.num_seats);
                    if (confirmBooking()) {
                        blockSeats(selected_seats, t1.start_seat, t1.num_seats);
                        booking_system.tickets[booking_system.count++] = t1;
                        handlePayment(t1.category == VIP ? t1.num_seats : 0, t1.category == GOLD ? t1.num_seats : 0, t1.category == SILVER ? t1.num_seats : 0);
                        printf("Booking confirmed.\n");
                        break;
                    } else {
                        printf("Booking cancelled.\n");
                    }
                } else {
                    printf("Seats not available. Please choose a different range.\n");
                }
            }

        } else if (choice == 2) {
            printBookings(&booking_system);
        } else if (choice == 3) {
            displayScreenStatus(screens);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
