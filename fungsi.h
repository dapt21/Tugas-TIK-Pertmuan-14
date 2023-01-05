#ifndef FUNGSI_H_INCLUDED
#define FUNGSI_H_INCLUDED

#include "listUser.h"
#include "listFilm.h"

void menuUser(adrUser dataUser, int &pilih);
void menuLogin(listUser &listU, adrUser &dataUserLogin);
void garis(int n);
void tambahUserDefault(listUser &listU);
void tambahFilmDefault(listFilm &listF);
void tambahRelasiDefault(listFilm listF, listUser listU);
void registrasiUser(listUser &listU);
void tambahFilm(listFilm &listF, adrUser dataUserLogin);
void tampilkanFilmSubcriber(listUser listU, adrUser dataUserLogin);
void tampilkanSemuaPemeran(listUser listU, adrFilm dataFilm);
void deleteRelasi(listUser listU, listFilm listF, adrUser &dataUserLogin);

#endif // FUNGSI_H_INCLUDED
