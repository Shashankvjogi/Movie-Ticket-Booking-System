
#include "movie.h"

int initializeSeats(Screen *screens) {
    int vip_size, gold_size, silver_size;
    vip_size = VIP_SEATS;
    gold_size = GOLD_SEATS;
    silver_size = SILVER_SEATS;
    for (int i = 0; i < NUM_SCREENS; i++) {
        for (int j = 0; j < vip_size; j++) {
            screens[i].vip[j] = 0;
        }
        for (int j = 0; j < gold_size; j++) {
            screens[i].gold[j] = 0;
        }
        for (int j = 0; j < silver_size; j++) {
            screens[i].silver[j] = 0;
        }
    }
    return 1;
}

int printSeats(Screen *screen, int vip_size, int gold_size, int silver_size) {
    printf("VIP Seats: ");
    for (int i = 0; i < vip_size; i++) {
        printf("%d ", screen->vip[i]);
    }
    printf("\nGOLD Seats: ");
    for (int i = 0; i < gold_size; i++) {
        printf("%d ", screen->gold[i]);
    }
    printf("\nSILVER Seats: ");
    for (int i = 0; i < silver_size; i++) {
        printf("%d ", screen->silver[i]);
    }
    printf("\n");
    return 1;
}


int areSeatsAvailable(int *seats, int start, int num_seats, int total_seats) {
    if (start + num_seats > total_seats) {
        return 0;
    }
    for (int i = start; i < start + num_seats; i++) {
        if (seats[i] != 0) {
            return 0;
        }
    }
    return 1;
}


int blockSeats(int *seats, int start, int num_seats) {
    for (int i = start; i < start + num_seats; i++) {
        seats[i] = 1;
    }
    return 1;
}


/*int unblockSeats(int *seats, int start, int num_seats) {
    for (int i = start; i < start + num_seats; i++) {
        seats[i] = 0;
    }
    return 1;
}*/


int confirmBooking() {
    char confirm;
    printf("Confirm booking? (Y/N): ");
    scanf(" %c", &confirm);
    return (confirm == 'Y' || confirm == 'y');
}


int handlePayment(int num_vip, int num_gold, int num_silver) {
    int total_amount = num_vip * PRICE_VIP + num_gold * PRICE_GOLD + num_silver * PRICE_SILVER;
    printf("Processing payment...\n");
    printf("Total amount: Rs %d\n", total_amount);
    printf("Payment completed.\n");
    return 1;
}


int displaySelectedSeats(int start, int num_seats) {
    printf("Selected seats: ");
    for (int i = start; i < start + num_seats; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return 1;
}


int printBookings(BookingSystem *booking_system) {
    if (booking_system->count == 0) {
        printf("No bookings found.\n");
        return 0;
    }

    printf("All Bookings:\n");
    for (int i = 0; i < booking_system->count; i++) {
        Ticket t = booking_system->tickets[i];
        printf("Booking #%d:\n", i + 1);
        printf("Name: %s\n", t.name);
        printf("Phone Number: %s\n", t.phone_num);
        printf("Screen: %d\n", t.screen + 1);
        printf("Category: %s\n", t.category == VIP ? "VIP" : (t.category == GOLD ? "GOLD" : "SILVER"));
        printf("Seats: %d-%d\n", t.start_seat, t.start_seat + t.num_seats - 1);
    }
    return 1;
}

int displayScreenStatus(Screen *screens) {
    for (int i = 0; i < NUM_SCREENS; i++) {
        printf("Screen %d Status:\n", i + 1);
        int vip_size, gold_size, silver_size;

        vip_size = VIP_SEATS;
        gold_size = GOLD_SEATS;
        silver_size = SILVER_SEATS;

       /* if (i == 0) {
            vip_size = VIP_SEATS;
            gold_size = GOLD_SEATS;
            silver_size = SILVER_SEATS;
        } else if (i == 1) {
            vip_size = VIP_SEATS;
            gold_size = GOLD_SEATS;
            silver_size = SILVER_SEATS;
        } else {
            vip_size = VIP_SEATS;
            gold_size = GOLD_SEATS;
            silver_size = SILVER_SEATS;
        }*/

        printSeats(&screens[i], vip_size, gold_size, silver_size);
    }
    return 1;
}


