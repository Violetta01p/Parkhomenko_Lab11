#include <iostream>
#include <regex>
#include <string>

using namespace std;

struct Event {
private:
    string name, location, time;

public:
    Event(const string& n, const string& loc, const string& t)
        : name(n), location(loc), time(t) {}

    void validateAndConvertTime() {
        regex time_format("(\\d{1,2}):(\\d{2})\\s?(AM|PM)", regex_constants::icase);
        smatch match;
        if (regex_match(time, match, time_format)) {
            int hours = stoi(match[1]), minutes = stoi(match[2]);
            string period = match[3];
            if (period == "PM" || period == "pm") hours = (hours % 12) + 12;
            else if (hours == 12) hours = 0;
            time = (hours < 10 ? "0" : "") + to_string(hours) + ":" + match[2].str();
        } else {
            cout << "Invalid time format! Expected format: HH:MM AM/PM\n";
        }
    }

    void displayEvent() const {
        cout << "Event Info:\nName: " << name << "\nLocation: " << location << "\nTime: " << time << "\n";
    }
};

int main() {
    Event event("Ceremony", "Kyiv", "07:00 PM");
    event.validateAndConvertTime();
    event.displayEvent();
    return 0;
}
