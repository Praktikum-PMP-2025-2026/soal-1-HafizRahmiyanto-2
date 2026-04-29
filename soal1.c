#include <stdio.h>
#include <string.h>

typedef struct data{
    char nama[20];
    char kategori[20];
    int tahun;
    int nilai;
}data;

void input(data* list, int N){
    char bufferNama[20];
    int bufferTahun=0;
    char bufferKategori[20];
    int bufferNilai=0;

    for(int i=0; i<N; i++){
        scanf("%s %s %d %d", bufferNama, bufferKategori, &bufferTahun, &bufferNilai);
        list[i].tahun = bufferTahun;
        list[i].nilai = bufferNilai;
        strcpy(list[i].nama, bufferNama);
        strcpy(list[i].kategori, bufferKategori);
    }
    return;
}

void urutkan(data* m, int N) {
    data temp;
    int i, j, tukar;

    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            tukar = 0;

            if (strcmp(m[j].kategori, m[j+1].kategori) > 0) {
                tukar = 1;
            } 
            else if (strcmp(m[j].kategori, m[j+1].kategori) == 0) {
                if (m[j].tahun > m[j+1].tahun) {
                    tukar = 1;
                } 
                else if (m[j].tahun == m[j+1].tahun) {
                    if (m[j].nilai < m[j+1].nilai) {
                        tukar = 1;
                    }
                    else if (strcmp(m[j].nama, m[j+1].nama) > 0){
                        tukar = 1;
                    }
                }
            }

            if (tukar == 1) {
                temp = m[j];
                m[j] = m[j+1];
                m[j+1] = temp;
            }
        }
    }
    return;
}

void tampilkan(data input[], int N){
    for(int i = 0; i<N; i++){
        printf("%s %s %d %d\n", input[i].nama, input[i].kategori, input[i].tahun, input[i].nilai);
    }
    return;
}

int main(){
    int N=0;
    scanf("%d", &N);
    data artefak[N];
    input(artefak, N);
    urutkan(artefak,N);
    tampilkan(artefak, N);
    return 0;
}

