# SuperMarket Management System

A comprehensive **Inventory & Order Management System** built in C++ that handles product tracking, customer orders, admin controls, and analytics.

## Features
- **Product & Inventory Management** (Add/Update/Delete products, track stock)
- **Shopping Cart & Order Processing**
- **Admin Dashboard** (Sales reports, low-stock alerts)
- **Customer Loyalty Program** (Reward points, discounts)
- **Analytics & Reporting** (Sales trends, demand tracking)

---

## Class Structure Overview

### 1. **Product Class**
Represents an item in inventory with:
- Attributes: `name`, `category`, `price`, `stock`, `seasonal`, `demandCount`
- Functions: Stock/price updates, demand tracking, getters/setters.

### 2. **CartItem Class**
Models items in a shopping cart:
- Attributes: `Product`, `quantity`
- Functions: Calculate subtotal, update quantity.

### 3. **PriorityQueue Class**
Tracks low-stock products:
- Functions: `add()`, `removeLowestStock()`, `displayLowStockAlerts()`.

### 4. **Admin Class**
Manages inventory and analytics:
- Key Functions:  
  - `addProduct()`, `updatePrice()`  
  - `viewSalesReports()`, `processOrders()`  
  - Password-protected access.

### 5. **Category Class**
Organizes products in a **BST**:
- Functions: `insert()`, `search()`, `deleteNode()`, `inOrderTraversal()`.

### 6. **Analytics Class**
Generates reports:
- Sales trends, customer behavior, inventory alerts.

### 7. **Inventory Class**
Core inventory operations:
- Linked lists for products/categories.
- Low-stock alerts via `PriorityQueue`.

### 8. **Order & OrderQueue Classes**
- **Order**: Handles order details, promo codes, status tracking.  
- **OrderQueue**: Processes orders (FIFO), updates product demand.

### 9. **ShoppingCart Class**
- Manages cart items with undo functionality (using `stack`).  
- Calculates totals, syncs with inventory.

### 10. **SystemLog Class**
Logs system events with timestamps.

### 11. **Customer & LoyaltyProgram Classes**
- `customerprofile`: Tracks IDs, names, reward points.  
- `loyaltyprogram`: Manages customer database with rewards.

---

## How It Works
1. **Admins** add/update products, view reports, and process orders.
2. **Customers** add items to cart, apply discounts, and place orders.
3. **System** tracks demand, low stock, and rewards automatically.

---

## Key Data Structures
- **BST** (Category-wise product organization)
- **Linked Lists** (Inventory/Category lists)
- **Queues** (Order processing)
- **Stacks** (Cart undo functionality)

---
