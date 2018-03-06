#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

void parse_command(string command);

struct Event {
	string name;
	int starttime;
	int length;
};

vector<Event> events;

int main() {

	while(true) {
		string command;
		cout << "Please enter your command>>";
		cin >> command;
		parse_command(command);
	}
}

void parse_command(string command) {
	if(command.compare("help")==0) {
		cout << "help : help command\n";
		cout << "enter : enter an event\n";
		cout << "delete : delete an event based on name\n";
		cout << "list : list all events\n";
	} else if (command.compare("enter")==0) {
		string name,length,time;
		cout << "What is the name of the event? >>";
		cin >> name;
		cout << "What is the time of the event? >>";
		cin >> time;
		cout << "What is the length of the event? >>";
		cin >> length;
		Event e;
		e.name = name;
		e.starttime = atoi(time.c_str());
		e.length = atoi(length.c_str());

		events.push_back(e);

	} else if (command.compare("delete") == 0) {
		string name;
		cout << "What event name would you like to delete? >>";
		cin >> name;

		int i = 0;

		for(vector<Event>::iterator it = events.begin(); it != events.end(); ++it, i++) {
			if((*it).name.compare(name)==0) {
				events.erase(events.begin() + i);
				return;
			}
		}

		cout << "Event not found. \n";
	} else if (command.compare("list") == 0) {
		for(Event e : events) {
			cout << "Event Name:" + e.name + "\n";
			cout << "Event Time: " + to_string(e.starttime) + "\n";
			cout << "Event Length: " + to_string(e.length) + "\n\n";
		}
	} else {
		cout << "command not recognized\n";
	}
	return;
}