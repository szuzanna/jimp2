//
// Created by Zuzanna on 06.04.2018.
//
#import "XXX.h"
XXX make_copy(XXX xxx) {
    return xxx;
}

int main() {
    //Konstrukcja obiektu za pomocą domyślnego konstruktora
    //nieciekawe
    XXX old_xxx {};

    //Konstrukcja obiektu na podstawie już zaincjalizowanego
    //z przeniesieniem old_xxx jest niszczony
    XXX new_xxx {std::move(old_xxx)};

    //znowu nieciekawy konstruktor domyślny...
    XXX another_xxx {};

    //tutaj przypisujemy stan obiektu jednego do drugiego
    //ale obydwa są już zaincjalizowane...
    //stan new_xxx teraz będzie w another_xxx, a sam new_xxx jest niszczony
    another_xxx = std::move(new_xxx);

    //tutaj zostanie wywoały konstruktor kopiujący (argument wysyłany przez wartość)
    //a następnie konstruktor przenoszący (bo wartość tymczasowa wytworzona przez funkcję make_copy()
    //i tak zaraz zginie
    XXX one_more = make_copy(another_xxx);
    //tutaj watość tymczasowa z funkcji make_copy już jest niszczona i wywoływany jest destruktor

    //...

    //tutaj kończy się zakres funkcji main i wszystkie trzy obiekty tracą ważność
    //zostają wywołane więc destruktory (na wszystkich trzech, ale tylko jeden ma ważny stan)
}



