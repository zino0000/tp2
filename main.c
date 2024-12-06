#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#include "file.h"
#include "custumer.h"
#include "game.h"
#include "rental.h"

void displayMenu() {
    // Implementation...

    printf("Main Menu:\n");
    printf("1. Add a rental\n");
    printf("2. Add a customer\n");
    printf("3. Add a game\n");
    printf("4. Search a rental\n");
    printf("5. Display the rentals list\n");
    printf("6. Display the customers list\n");
    printf("7. Display the games list\n");
    printf("0. Exit\n");
    printf("Choose an option (0-9): ");
}




int main() {

srand(time(NULL));
    char s;
    TOF *cfile, *gfile, *rfile;
    
    printf("\nIf you want to load data type A \nIf you want to create a new list type N\n");
    scanf(" %c", &s);
    cfile = open_file("c.txt", s);
    gfile = open_file("g.txt", s);
    rfile = open_file("r.txt", s);
    
    if (cfile == NULL || gfile == NULL || rfile == NULL) {
        printf("Error opening files.\n");
        return -1;
    }
   int id;
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRental(rfile, cfile, gfile);
                break;
            case 2:
                addCustomer(cfile);
                break;
            case 3:
                addGame(gfile);
                break;
            case 4:
           
                 printf("give the id of the rental you want to search");
                 scanf("%d",&id);
                Rentalf s = searchRental(rfile,id);
                if (s.rid == 0){
                    printf("rental not found ");
                }else{
                    Rental r;
                    r.a = searchcust(cfile,s.cid);
                    r.b = searchgame(gfile,s.gid);
                    r.rid = s.rid ;
                    r.ren = s.t1;
                    r.rut = s.t2;
                    r.price = s.price ;
                    displayRental(&r);
                }
                break;
            case 5:
                displayRentals(rfile, cfile, gfile);
                break;
            case 6:
                displayCustomers(cfile);
                break;
            case 7:
                displayGames(gfile);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
