#include <iostream>
#include <string>
using namespace std;

const int MAX_TICKETS = 100;

class Ticket {
private:
    string pnr;
    string passengerName;
    string flightNo;
    string seatNo;
    double price;
    bool cancelled;

public:
    Ticket(string p = "", string pn = "", string f = "", string s = "", double pce = 0.0, bool c = false) 
        : pnr(p), passengerName(pn), flightNo(f), seatNo(s), price(pce), cancelled(c) {}
    
    // Getters
    string getPnr() const { return pnr; }
    string getPassengerName() const { return passengerName; }
    string getFlightNo() const { return flightNo; }
    string getSeatNo() const { return seatNo; }
    double getPrice() const { return price; }
    bool isCancelled() const { return cancelled; }

    // Setters
    void setSeatNo(string s) { seatNo = s; }
    void cancel() { cancelled = true; }
};

// Refund calculation (does not modify ticket price!)
double calculateRefund(const Ticket& t, int daysBeforeFlight = 40) {
    if (!t.isCancelled()) return 0.0; 

    if (daysBeforeFlight > 30) return t.getPrice();       // Full refund
    else if (daysBeforeFlight >= 7) return t.getPrice() * 0.5; // 50% refund
    else return 0.0;                                      // No refund
}

class BookingSystem {
private:
    Ticket tickets[MAX_TICKETS];
    int ticketCount;

public:
    BookingSystem() : ticketCount(0) {}
    
    bool addTicket(const Ticket& t) {
        if (ticketCount < MAX_TICKETS) {
            tickets[ticketCount++] = t;
            return true;
        }
        return false;
    }

    bool cancelTicket(string oldPNR, string newPNR = "") {
        for (int i = 0; i < ticketCount; i++) {
            if (tickets[i].getPnr() == oldPNR && !tickets[i].isCancelled()) {
                tickets[i].cancel();

                // If reallocation PNR is provided
                if (!newPNR.empty()) {
                    for (int j = 0; j < ticketCount; j++) {
                        if (tickets[j].getPnr() == newPNR && !tickets[j].isCancelled()) {
                            tickets[j].setSeatNo(tickets[i].getSeatNo());
                            return true; // cancellation + seat reallocation successful
                        }
                    }
                    return false; // cancellation success, reallocation failed
                }

                return true; // cancellation only
            }
        }
        return false; // ticket not found
    }

    void refundSummaryReport() {
        double totalRefund = 0.0;
        for (int i = 0; i < ticketCount; i++) {
            if (tickets[i].isCancelled()) {
                double refund = calculateRefund(tickets[i]);
                cout << "PNR: " << tickets[i].getPnr() 
                     << ", Passenger: " << tickets[i].getPassengerName() 
                     << ", Price: " << tickets[i].getPrice() 
                     << ", Refund: " << refund << endl;
                totalRefund += refund;
            }
        }
        cout << "Total refunds issued: " << totalRefund << endl;
    }
};

int main() {
    BookingSystem bs;
    bs.addTicket(Ticket("PNR1", "John Doe", "F101", "A1", 200.0, false));
    bs.addTicket(Ticket("PNR2", "Jane Smith", "F102", "B2", 250.0, false));
    bs.addTicket(Ticket("PNR3", "Alice Brown", "F103", "C3", 300.0, true));

    cout << "\n--- Initial Refund Report ---\n";
    bs.refundSummaryReport();

    if (bs.cancelTicket("PNR1", "PNR2")) {
        cout << "\nTicket cancellation and seat reallocation successful.\n";
    } else {
        cout << "\nTicket cancellation failed.\n";
    }

    cout << "\n--- Final Refund Report ---\n";
    bs.refundSummaryReport();

    return 0;
}
