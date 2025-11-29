void createListUKM_c103012400197(ListUKM_103012400197 &L) {
    firstUKM_103012400197(L) = NULL;
}

addressUKM_103012400197 isEmptyUKM_103012400197(ListUKM_103012400197 L) {
    return firstUKM_103012400197(L) == NULL;
}

AddressUKM_103012400197 createListUKM_103012400197(InfotypeUKM_103012400197 x) {
    AddressUKM_103012400197 P = new elmenUKM_103012400197;
    infoUKM_103012400197(P) = x;
    nextUKM_103012400197(P) = NULL;
    return P;
}

void insertLastUKM_103012400197(ListUKM_103012400197 &L, AddressUKM_103012400197 P) {
    if (isEmptyUKM_103012400197(L)) {
        firstUKM_103012400197(L) = P;
    } else {
        AddressUKM_103012400197 Q = firstUKM_103012400197(L);
        while (nextUKM_103012400197(Q) != NULL) {
            Q = nextUKM_103012400197(Q);
        }
        nextUKM_103012400197(Q) = P;
    }
}

void printInfoUKM_103012400197(ListUKM_103012400197 L) {
    AddressUKM_103012400197 P = firstUKM_103012400197(L);
    while (P != NULL) {
        cout << "- " << infoUKM_103012400197(P) << endl;
        P = nextUKM_103012400197(P);
    }
}
