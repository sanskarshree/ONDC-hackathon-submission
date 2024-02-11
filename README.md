# Cloud Kitchen and Merchant Application Hackathon Solution

This repository contains a solution developed for the Cloud Kitchen and Merchant Application Hackathon. The solution is designed to address challenges faced by users of cloud kitchen and merchant applications through the implementation of efficient data structures and algorithms.

## Overview

The solution utilizes a combination of data structures including B+ trees and maps to optimize the storage and retrieval of information within the application. The pseudocode provided outlines the implementation details of the solution, including functions for inserting cell values, performing lookups based on rows and columns, and example usage scenarios.

## Key Components

### BPlusTree Class

The `BPlusTree` class represents the B+ tree data structure used for organizing and storing `seller_id` and `pincode` values.

### MapEntry Class

The `MapEntry` class represents entries in the maps (`Map1` and `Map2`), containing pointers to B+ trees and type indicators (0 or 1).

### Functions

- `insertCellValue(row, col, value, seller_id, pincode)`: Inserts a cell value into the data structure based on the provided row, column, seller_id, and pincode.
- `lookupByRow(row, pincode)`: Performs a lookup based on the specified row and pincode, returning the corresponding value.
- `lookupByColumn(col, seller_id)`: Performs a lookup based on the specified column and seller_id, returning the corresponding value.

## Usage

Example usage of the provided pseudocode is included in the README file, demonstrating how to insert cell values and perform lookups based on rows and columns.

```plaintext
insertCellValue(1, 1, 1, 123, 456)
insertCellValue(2, 1, 0, 789, 456)
insertCellValue(3, 1, 1, 123, 789)

resultRow = lookupByRow(2, 456) // Returns 0
resultColumn = lookupByColumn(2, 123) // Returns 1
