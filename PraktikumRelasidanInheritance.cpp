#include <iostream>
#include <vector>

using namespace std;

// class utama
class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->nama = nama;
        this->email = email;

        id = generateId();
    }

    int generateId() {
        globalId++;
        return globalId;
    }

    int getId() {
        return id;
    }

    string getNama() {
        return nama;
    }

    string getEmail() {
        return email;
    }
};

int User::globalId = 0;

// class member
class Member : public User {
private:
    bool status;

public:
    Member(string nama, string email)
        : User(nama, email) {

        status = true;
    }

    void setStatus(bool status) {
        this->status = status;
    }

    bool getStatus() {
        return status;
    }

    void showProfile() {

        cout << "\n=== Profile Member ===" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;

        if(status == true) {
            cout << "Status : Aktif" << endl;
        }
        else {
            cout << "Status : Nonaktif" << endl;
        }
    }
};

// class admin
class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {

    }

    void showAllMember(vector<Member> &member) {

        cout << "\n=== Semua Member ===" << endl;

        for(int i = 0; i < member.size(); i++) {

            cout << "ID     : " << member[i].getId() << endl;
            cout << "Nama   : " << member[i].getNama() << endl;
            cout << "Email  : " << member[i].getEmail() << endl;

            if(member[i].getStatus() == true) {
                cout << "Status : Aktif" << endl;
            }
            else {
                cout << "Status : Nonaktif" << endl;
            }

            cout << "-------------------" << endl;
        }
    }

    void toggleActivationMember(vector<Member> &member, int idCari) {

        for(int i = 0; i < member.size(); i++) {

            if(member[i].getId() == idCari) {

                if(member[i].getStatus() == true) {
                    member[i].setStatus(false);
                }
                else {
                    member[i].setStatus(true);
                }

                cout << "\nStatus member berhasil diubah!" << endl;
                return;
            }
        }

        cout << "\nMember tidak ditemukan!" << endl;
    }
};

int main() {

    // buat admin
    Admin admin("Admin", "admin@gmail.com");

    // list member
    vector<Member> daftarMember;

    // tambah member
    daftarMember.push_back(Member("Ahmad Fadhil", "ahmad.fadhil@gmail.com"));
    daftarMember.push_back(Member("Kobo Kanaeru", "kobo@gmail.com"));
    daftarMember.push_back(Member("Vestia Zeta", "zeta@gmail.com"));

    // tampil semua member
    admin.showAllMember(daftarMember);

    // ubah status member id 2
    admin.toggleActivationMember(daftarMember, 2);

    // tampil lagi setelah diubah
    admin.showAllMember(daftarMember);

    // tampil profile salah satu member
    daftarMember[2].showProfile();

    return 0;
}