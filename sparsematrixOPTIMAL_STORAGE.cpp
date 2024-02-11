#include <iostream>
#include <unordered_map>

class BPlusTree {};

class MapEntry {
public:
    BPlusTree* pointer;
    int type;
    MapEntry(BPlusTree* ptr, int t) : pointer(ptr), type(t) {}
};

std::unordered_map<int, MapEntry*> Map1;
std::unordered_map<int, MapEntry*> Map2;

void insertCellValue(int row, int col, int value, int seller_id, int pincode);

MapEntry* getMapEntry(int row, int col, int seller_id, int pincode);

MapEntry* getOrCreateMapEntry(std::unordered_map<int, MapEntry*>& map, int key, int type);

int getKey(int row, int col, int seller_id, int pincode);

int lookupByRow(int row, int pincode);

int lookupByColumn(int col, int seller_id);

int lookup(std::unordered_map<int, MapEntry*>& map, int key, int index);

int main() {
    insertCellValue(1, 1, 1, 123, 456);
    insertCellValue(2, 1, 0, 789, 456);
    insertCellValue(3, 1, 1, 123, 789);

    int resultRow = lookupByRow(2, 456);
    int resultColumn = lookupByColumn(2, 123);

    return 0;
}

void insertCellValue(int row, int col, int value, int seller_id, int pincode) {
    MapEntry* mapEntry = getMapEntry(row, col, seller_id, pincode);
    mapEntry->pointer->insert(getKey(row, col, seller_id, pincode), value);
}

MapEntry* getMapEntry(int row, int col, int seller_id, int pincode) {
    if (row < col) {
        return getOrCreateMapEntry(Map1, seller_id, 0);
    } else {
        return getOrCreateMapEntry(Map2, pincode, 1);
    }
}

MapEntry* getOrCreateMapEntry(std::unordered_map<int, MapEntry*>& map, int key, int type) {
    if (map.find(key) != map.end()) {
        return map[key];
    } else {
        BPlusTree* tree = new BPlusTree();
        MapEntry* entry = new MapEntry(tree, type);
        map[key] = entry;
        return entry;
    }
}

int getKey(int row, int col, int seller_id, int pincode) {
    if (row < col) {
        return seller_id;
    } else {
        return pincode;
    }
}

int lookupByRow(int row, int pincode) {
    return lookup(Map2, pincode, row);
}

int lookupByColumn(int col, int seller_id) {
    return lookup(Map1, seller_id, col);
}

int lookup(std::unordered_map<int, MapEntry*>& map, int key, int index) {
    if (map.find(key) != map.end()) {
        return map[key]->pointer->get(index);
    }
    return -1;
}