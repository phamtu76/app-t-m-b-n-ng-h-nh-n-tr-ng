#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User {
    int id;
    string name;
};

struct Route {
    int userId;
    string destination;
};

vector<User> users;
vector<Route> routes;

void registerUser() {
    int id = users.size() + 1;
    string name;
    cout << "Nhap ten: ";
    cin >> name;
    users.push_back({id, name});
    cout << "Dang ky thanh cong!\n";
}

void addRoute(int userId) {
    string dest;
    cout << "Nhap diem den truong: ";
    cin >> dest;
    routes.push_back({userId, dest});
    cout << "Da them lo trinh!\n";
}

void findMatches(int userId) {
    cout << "Tim ban dong hanh...\n";
    for (auto &my : routes) {
        if (my.userId == userId) {
            for (auto &other : routes) {
                if (other.userId != userId && other.destination == my.destination) {
                    cout << "Ban dong hanh: " << users[other.userId - 1].name
                         << " cung den " << other.destination << "\n";
                }
            }
        }
    }
}

int main() {
    int choice, currentUser = -1;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Dang ky\n2. Chon nguoi dung\n3. Them lo trinh\n4. Tim ban dong hanh\n5. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: {
                int id;
                cout << "Nhap ID nguoi dung: ";
                cin >> id;
                if (id > 0 && id <= users.size()) {
                    currentUser = id;
                    cout << "Dang nhap voi user " << users[id-1].name << "\n";
                } else cout << "Khong ton tai.\n";
                break;
            }
            case 3: if (currentUser != -1) addRoute(currentUser); else cout << "Chua chon user!\n"; break;
            case 4: if (currentUser != -1) findMatches(currentUser); else cout << "Chua chon user!\n"; break;
            case 5: return 0;
            default: cout << "Lua chon khong hop le.\n";
        }
    }
}
