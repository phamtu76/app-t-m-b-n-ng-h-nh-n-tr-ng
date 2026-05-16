#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

void saveData() {
    ofstream fout("data.txt");
    for (auto &u : users) {
        fout << u.id << " " << u.name << "\n";
    }
    fout << "---\n"; // ngăn cách user và route
    for (auto &r : routes) {
        fout << r.userId << " " << r.destination << "\n";
    }
    fout.close();
}

void loadData() {
    ifstream fin("data.txt");
    if (!fin) return; // chưa có file thì bỏ qua
    users.clear();
    routes.clear();

    string line;
    while (fin >> line && line != "---") {
        User u;
        u.id = stoi(line);
        fin >> u.name;
        users.push_back(u);
    }
    while (fin >> line) {
        Route r;
        r.userId = stoi(line);
        fin >> r.destination;
        routes.push_back(r);
    }
    fin.close();
}

void registerUserAndRoute() {
    int id = users.size() + 1;
    string name, dest;

    cout << "Nhap ten: ";
    cin >> name;
    users.push_back({id, name});

    cout << "Nhap diem den truong: ";
    cin >> dest;
    routes.push_back({id, dest});

    cout << "Dang ky thanh cong!\n";

    // Lưu dữ liệu sau khi đăng ký
    saveData();

    // Kiểm tra người phù hợp
    bool found = false;
    for (auto &other : routes) {
        if (other.userId != id && other.destination == dest) {
            cout << "Tim thay ban dong hanh phu hop!\n";
            cout << "Nguoi dung: " << users[other.userId - 1].name
                 << " cung den " << dest << "\n";
            found = true;
        }
    }
    if (!found) cout << "Khong co nguoi phu hop.\n";
}

int main() {
    loadData(); // đọc dữ liệu cũ khi khởi động

    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- MENU ---\n";
        cout << "1. Dang ky (ten + lo trinh)\n";
        cout << "2. Thoat\n";
        cout << "Chon: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap sai! Vui long nhap so.\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerUserAndRoute();
                break;
            case 2:
                cout << "Tam biet!\n";
                running = false;
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}
