void createListUKM_c103012400197(ListUKM_103012400197 &L) {
    firstUKM_103012400197(L) = NULL;
}

AddressUKM isEmptyUKM_103012400197(ListUKM L) {
    return L.first = nullptr;
}

AddressUKM_103012400197 createListUKM_103012400197(InfotypeUKM_103012400197 x) {
    AddressUKM_103012400197 P = new elmenUKM_103012400197;
    infoUKM_103012400197(P) = x;
    nextUKM_103012400197(P) = NULL;
    return P;
}

void insertLastUKM_103012400197(ListUKM &L, AddressUKM p) {
    if (isEmptyUKM_103012400197(L)) {
        L.first = p;
    } else {
        AddressUKM q = L.first;
        while (q -> next != nullptr) {
            q = q -> next;
        }
        q -> next = p;
    }
}

void printInfoUKM_103012400197(ListUKM L) {
    AddressUKM p = L.first;
    while (p != nullptr) {
        cout << "- " << p -> info << endl;
        p = p -> next;
    }
}