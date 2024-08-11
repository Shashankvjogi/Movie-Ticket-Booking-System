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

            printf("Select Screen (1, 2, or 3): ");
            scanf("%d", &t1.screen);
            t1.screen -= 1;

            int vip_size, gold_size, silver_size;

            if (t1.screen == 0) {
                vip_size = VIP_SEATS;
                gold_size = GOLD_SEATS;
                silver_size = SILVER_SEATS;
            } else if (t1.screen == 1) {
                vip_size = VIP_SEATS;
                gold_size = GOLD_SEATS;
                silver_size = SILVER_SEATS;
            } else {
                vip_size = VIP_SEATS;
                gold_size = GOLD_SEATS;
                silver_size = SILVER_SEATS;
            }

            Screen *current_screen = &screens[t1.screen];

            while (1) {
                printSeats(current_screen, vip_size, gold_size, silver_size);

                printf("Select seat category (0: VIP, 1: GOLD, 2: SILVER): ");
                scanf("%d", &t1.category);

                int *selected_seats;
                int selected_size;

                if (t1.category == VIP) {
                    selected_seats = current_screen->vip;
                    selected_size = vip_size;
                } else if (t1.category == GOLD) {
                    selected_seats = current_screen->gold;
                    selected_size = gold_size;
                } else if (t1.category == SILVER) {
                    selected_seats = current_screen->silver;
                    selected_size = silver_size;
                }

                printf("Enter starting seat number (0 to %d): ", selected_size - 1);
                scanf("%d", &t1.start_seat);

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
