
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIP 1
#define GOLD 2
#define SILVER 3

#define NUM_SCREENS 3
#define VIP_SEATS 10
#define GOLD_SEATS 20
#define SILVER_SEATS 30

#define MAX_BOOKINGS 60

#define PRICE_VIP 300
#define PRICE_GOLD 200
#define PRICE_SILVER 150


typedef struct {
    int vip[VIP_SEATS];
    int gold[GOLD_SEATS];
    int silver[SILVER_SEATS];
} Screen;


typedef struct {
    char name[20];
    char phone_num[11];
    int screen;
    int start_seat;
    int num_seats;
    int category;
} Ticket;

typedef struct {
    Ticket tickets[MAX_BOOKINGS];
    int count;
} BookingSystem;


int initializeSeats(Screen *screens);
int printSeats(Screen *screen, int vip_size, int gold_size, int silver_size);
int areSeatsAvailable(int *seats, int start, int num_seats, int total_seats);
int blockSeats(int *seats, int start, int num_seats);
int confirmBooking();
int handlePayment(int num_vip, int num_gold, int num_silver);
int displaySelectedSeats(int start, int num_seats);
int printBookings(BookingSystem *booking_system);
int displayScreenStatus(Screen *screens);


