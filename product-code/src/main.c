#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 101

// Struct to represent a product item record
struct Product {
    int product_code;
    char name[MAX_NAME_LENGTH];
    int price;
};

// Array to store product records
struct Product products[MAX_PRODUCTS];
int product_count = 0;

void insert_product(int product_code, const char* name, const int price) {
    // Check if the product_code is already registered
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_code == product_code) {
            return; // Product already registered, do nothing
        }
    }

    // Check if the array is full
    if (product_count >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    // Add the new product entry
    products[product_count].product_code = product_code;
    strncpy(products[product_count].name, name, MAX_NAME_LENGTH - 1);
    products[product_count].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    products[product_count].price = price;

    product_count++;
}

void remove_product(int product_code) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_code == product_code) {
            // Remove the product by shifting the subsequent elements
            for (int j = i; j < product_count - 1; j++) {
                products[j] = products[j + 1];
            }
            product_count--;
            return;
        }
    }
}

int get_product_price(int product_code) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_code == product_code) {
            return products[i].price;
        }
    }
    return -1; // Product not found
}

char* get_product_name(int product_code) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_code == product_code) {
            return products[i].name;
        }
    }
    return NULL; // Product not found
}

int main() {
    // Usage example
    // insert_product(101, "Product A", 10);
    // insert_product(102, "Product B", 20);
    // insert_product(103, "Product C", 30);

    // printf("Product price for code 102: %d\n", get_product_price(102));
    // printf("Product name for code 103: %s\n", get_product_name(103));

    // remove_product(101);
    // printf("Product price for code 101: %d\n", get_product_price(101));

  assert(get_product_price(42)==-1);
  insert_product(42, "computer", 1000);
  insert_product(42, "duplicate", 2000);
  insert_product(123123, "monitor", 10);
  assert(get_product_price(42)==1000);
  assert(strcmp(get_product_name(42),"computer")==0);
  assert(get_product_price(123123)==10);
  assert(strcmp(get_product_name(123123),"monitor")==0);
  remove_product(42);
  assert(get_product_price(42)==-1);
  assert(get_product_price(123123)==10);

  return 0;
}
