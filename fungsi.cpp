#include "fungsi.h"
#include "listFilm.h"
#include "listUser.h"

userSubcriber infoU[5] = {
    {id: 1, nama: "Adam", alamat: "NY city", gmail: "adam@gmail.com", umur: 21},
    {id: 2, nama: "Shelya", alamat: "Berlin", gmail: "Shelya@gmail.com", umur: 35},
    {id: 3, nama: "youcannotseeme", alamat: "British", gmail: "jhon@gmail.com", umur: 31},
    {id: 4, nama: "nibaa", alamat: "Kalbar", gmail: "nibb@gmail.com", umur: 29},
    {id: 5, nama: "gatausiapa", alamat: "Sumsel", gmail: "a@gmail.com", umur: 25}
};

filmNetflix infoF[5] = {
    {id: 1, judul: "Pirrate of the carrabine", durasi: "1:30 Jam", desc: "gatauapa1", studio: "gatausiapa1", tahunRilis: 2012},
    {id: 2, judul: "Junadi & Yoga", durasi: "1:49 Jam", desc: "gatauapa2", studio: "gatausiapa2", tahunRilis: 2002},
    {id: 3, judul: "Titansic", durasi: "2:29 Jam", desc: "gatauapa3", studio: "gatausiapa3", tahunRilis: 2014},
    {id: 4, judul: "Highschool DxD", durasi: "3:21 Jam", desc: "idkanymore1", studio: "PinkPinaple", tahunRilis: 2016},
    {id: 5, judul: "Overflow Maybe", durasi: "12:34 Jam", desc: "same,fakdissit", studio: "PinkPinaple", tahunRilis: 2022}
};

void garis(int n){
    for(int i = 0; i < n; i++){
        cout<<"=";
    }
    cout<<endl;
}

void tambahFilmDefault(listFilm &listF){
    for(int i = 0; i < 5; i++){
        insertLastFilm(listF, createElmFilm(infoF[i]));
    }
}

void tambahUserDefault(listUser &listU){
    for(int i = 0; i < 5; i++){
        insertFirstUser(listU, createElmUser(infoU[i]));
    }
}

void menuLogin(listUser &listU, adrUser &dataUserLogin){
    string gmail;
    int regis;

    garis(30);
    cout<<"Welcome to Netflix"<<endl;
    garis(30);
    cout<<"1. Login"<<endl;
    cout<<"2. Registrasi"<<endl;
    garis(30);
    cout<<"pilih: ";
    cin>>regis;

    if(regis == 1){
        system("cls");
        garis(30);
        cout<<"Login to Netflix"<<endl;
        garis(30);
        cout<<"gmail: ";
        cin>>gmail;

        if(cariDataUser(listU, gmail) != NULL){
            system("cls");
            dataUserLogin = cariDataUser(listU, gmail);
        }else{
            system("cls");

            garis(30);
            cout<<"Gmail tidak ditemukan"<<endl;
            garis(30);
            cout<<"tekan enter...";
            getch();

            system("cls");
            menuLogin(listU, dataUserLogin);
        }
    }else if(regis == 2){
        system("cls");
        registrasiUser(listU);
    }else{
        system("cls");
        garis(30);
        cout<<"Pilihan tidak ada"<<endl;
        garis(30);
        cout<<"tekan enter...";
        getch();
        system("cls");
        menuLogin(listU, dataUserLogin);
    }
}

void menuUser(adrUser dataUserLogin, int &pilih){
    garis(50);
    cout<<"KW Netflix APP V.1.0"<<endl;
    garis(50);
    cout<<"ID: "<<infoUser(dataUserLogin).id<<endl;
    cout<<"Welcome: "<<infoUser(dataUserLogin).nama<<endl;
    garis(50);
    cout<<"\t\t\tMenu"<<endl;
    garis(50);

    cout<<"1. Subcriber Film"<<endl;
    cout<<"2. Unsubcriber Film"<<endl;
    cout<<"3. Tampilkan Film Subcriber saya"<<endl;
    cout<<"4. Mencari Film Subcriber saya"<<endl;
    cout<<"5. Hapus akun"<<endl;
    cout<<"0. Logout"<<endl;
    garis(50);
    cout<<"Pilih menu: ";
    cin>>pilih;
}

void registrasiUser(listUser &listU){
    userSubcriber infoU;

    garis(50);
    cout<<"Registrasi KW Netflix"<<endl;
    garis(50);

    infoU.id = infoUser(firstUser(listU)).id + 1;
    cout<<"Nama Pengguna: ";
    cin>>infoU.nama;
    cout<<"Alamat: ";
    cin>>infoU.alamat;
    cout<<"Gmail: ";
    cin>>infoU.gmail;
    cout<<"Umur: ";
    cin>>infoU.umur;

    system("cls");

    insertFirstUser(listU, createElmUser(infoU));

    garis(50);
    cout<<"Registrasi berhasil"<<endl;
    garis(50);
    cout<<"tekan enter...";

    getch();

    system("cls");
}

void tambahFilm(listFilm &listF, adrUser dataUserLogin){
    filmNetflix infoF;
    adrFilm dataFilm;

    string judul;
    char cek;

    garis(50);
    cout<<"Subcribe Film Netflix"<<endl;
    garis(50);

    showAllFilm(listF);

    cout<<"Pilih Judul untuk di subcribe: ";
    cin.ignore();
    getline(cin, judul);
    garis(50);

    dataFilm = cariDataFilm(listF, judul);
    if(dataFilm != NULL){
        insertLastChild(dataUserLogin, createElmChild(dataFilm));
        cout<<"Subcribe Film berhasil"<<endl;
        garis(50);
        cout<<endl;
    }else{
        cout<<"Subcribe Film Netflix"<<endl;
        garis(50);
        cout<<"Tambahkan Film?(Y/N): ";
        cin>>cek;

        if(cek == 'Y' || cek == 'y'){
            infoF.id = autoIncrementIDFilm(listF);
            cout<<"Judul Film: ";
            cin>>infoF.judul;
            cout<<"Durasi: ";
            cin>>infoF.durasi;
            cout<<"Desc: ";
            cin>>infoF.desc;
            cout<<"Studio: ";
            cin>>infoF.studio;
            cout<<"Tahun rilis: ";
            cin>>infoF.tahunRilis;

            insertLastFilm(listF, createElmFilm(infoF));
            insertLastChild(dataUserLogin, createElmChild(createElmFilm(infoF)));

            garis(50);
            cout<<"Subcribe Film berhasil"<<endl;
            garis(50);
            cout<<endl;
        }else{
            cout<<"Gagal Subcribe Film"<<endl;
            garis(50);
            cout<<endl;
        }
    }
}

void deleteRelasi(listUser listU, listFilm listF, adrUser &dataUserLogin){
    string judul;
    adrChild delChild, dataDelFilm;

    garis(50);
    if(firstChild(dataUserLogin) != NULL){
        showAllChild(dataUserLogin);

        cout<<"Judul Film untuk di unsubcribe: ";
        cin.ignore();
        getline(cin, judul);

        delChild = cekRelasiChild(dataUserLogin, judul);

        if(delChild != NULL){
            if(firstChild(dataUserLogin) == delChild){
                deleteFirstChild(dataUserLogin, dataDelFilm);
            }else{
                deleteAfterChild(dataUserLogin, delChild, dataDelFilm);
            }
            garis(50);
            cout<<"Film di Unsubcribe"<<endl;
            garis(50);
            cout<<"Judul: "<<infoFilm(infoChild(dataDelFilm)).judul<<endl;
            cout<<"Studio: "<<infoFilm(infoChild(dataDelFilm)).studio<<endl;
        }else{
            cout<<"Film tidak ditemukan"<<endl;
        }
    }else{
        cout<<"Tidak memiliki Subcriber film"<<endl;
    }
    garis(50);
}
