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
    bool found = false;
    for (auto &my : routes) {
        if (my.userId == userId) {
            for (auto &other : routes) {
                if (other.userId != userId && other.destination == my.destination) {
                    cout << "Ban dong hanh: " << users[other.userId - 1].name
                         << " cung den " << other.destination << "\n";
                    found = true;
                }
            }
        }
    }
    if (!found) cout << "Khong tim thay ban dong hanh.\n";
}

int main() {
    int choice = 0;
    int currentUser = -1;
    bool running = true;

    while (running) {
        cout << "\n--- MENU ---\n"
             << "1. Dang ky | 2. Chon nguoi dung | 3. Them lo trinh | 4. Tim ban dong hanh | 5. Thoat\n"
             << "Nhap lua chon: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap sai! Vui long nhap so tu 1-5.\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2: {
                int id;
                cout << "Nhap ID nguoi dung: ";
                cin >> id;
                if (id > 0 && id <= users.size()) {
                    currentUser = id;
                    cout << "Dang nhap voi user " << users[id - 1].name << "\n";
                } else {
                    cout << "Khong ton tai nguoi dung nay.\n";
                }
                break;
            }
            case 3:
                if (currentUser != -1)
                    addRoute(currentUser);
                else
                    cout << "Vui long chon nguoi dung truoc!\n";
                break;
            case 4:
                if (currentUser != -1)
                    findMatches(currentUser);
                else
                    cout << "Vui long chon nguoi dung truoc!\n";
                break;
            case 5:
                cout << "Tam biet!\n";
                running = false;
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}
