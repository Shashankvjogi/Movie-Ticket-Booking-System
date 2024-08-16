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
    return SUCCESS;
}

int printSeats(Screen *screen, int vip_size, int gold_size, int silver_size) {
    printf("VIP Seats   :   ");
    for (int i = 0; i < vip_size; i++) {
        printf("%d ", screen->vip[i]);
    }
    printf("\nGOLD Seats  :   ");
    for (int i = 0; i < gold_size; i++) {
            if(i==10) printf("\n\t\t");
        printf("%d ", screen->gold[i]);
    }
    printf("\nSILVER Seats:   ");
    for (int i = 0; i < silver_size; i++) {
         if(i==10 || i==20) printf("\n\t\t");
        printf("%d ", screen->silver[i]);
    }
    printf("\n");
    return SUCCESS;
}


int areSeatsAvailable(int *seats, int start, int num_seats, int total_seats) {
    if (start + num_seats > total_seats) {
        return FAILURE;
    }
    for (int i = start; i < start + num_seats; i++) {
        if (seats[i] != 0) {
            return FAILURE;
        }
    }
    return SUCCESS;
}


int blockSeats(int *seats, int start, int num_seats) {
    for (int i = start; i < start + num_seats; i++) {
        seats[i] = 1;
    }
    return SUCCESS;
}


int confirmBooking() {
    char confirm;
    printf("CONFIRM BOOKING? (Y/N): ");
    scanf(" %c", &confirm);
    printf("\n");
    return (confirm == 'Y' || confirm == 'y');
}


int handlePayment(int num_vip, int num_gold, int num_silver) {
    int total_amount = num_vip * PRICE_VIP + num_gold * PRICE_GOLD + num_silver * PRICE_SILVER;
    printf("Processing payment...\n\n");
    printf("Total amount: Rs %d\n\n", total_amount);
    printf("Payment completed.\n\n");
    return SUCCESS;
}


int displaySelectedSeats(int start, int num_seats) {
    printf("Selected seats: ");
    for (int i = start; i < start + num_seats; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return SUCCESS;
}


int printBookings(BookingSystem *booking_system) {
    if (booking_system->count == 0) {
        printf("NO BOOKINGS FOUND.\n");
        printf("\n");
        return FAILURE;
    }

    printf("All Bookings:\n");
    printf("\n");
    for (int i = 0; i < booking_system->count; i++) {
        Ticket t = booking_system->tickets[i];
        printf("\n");
        printf("BOOKING ID : %d\n", i + 1);
        printf("NAME: %s\n", t.name);
        printf("PHONE NUMBER: %s\n", t.phone_num);
        printf("SCREEN: %d\n", t.screen + 1);
        printf("CATEGORY: %s\n", t.category == VIP ? "VIP" : (t.category == GOLD ? "GOLD" : "SILVER"));
        printf("SEATS: %d-%d\n", t.start_seat, t.start_seat + t.num_seats - 1);
        printf("\n");
    }
    return SUCCESS;
}

int displayScreenStatus(Screen *screens) {
    for (int i = 0; i < NUM_SCREENS; i++) {
        printf("Screen %d Status:\n", i + 1);
        int vip_size, gold_size, silver_size;

        vip_size = VIP_SEATS;
        gold_size = GOLD_SEATS;
        silver_size = SILVER_SEATS;


        printSeats(&screens[i], vip_size, gold_size, silver_size);
    }
    return SUCCESS;
}


