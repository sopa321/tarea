void decimalABinario(ListaDoble& lista, int numero) {
    while (numero > 0) {
        insertarInicio(lista, numero % 2);
        numero /= 2;
    }
}
