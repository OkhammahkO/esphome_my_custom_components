# Kogan SmarterHome™ Smart Antibacterial Wash & Dry Electric Bidet Toilet Seat

This yaml provides ESPHome support for the Kogan SmarterHome™ Smart Antibacterial Wash & Dry Electric Bidet Toilet Seat.  

## Product Details
Product Name:      KOGAN SMARTERHOME™ SMART ANTIBACTERIAL WASH & DRY ELECTRIC BIDET TOILET SEAT  
Product Listing:   https://www.kogan.com/au/buy/kogan-smarterhome-smart-antibacterial-wash-dry-electric-bidet-toilet-seat/  
Product Code:      KASMABIDETA  
Product Manual:    https://assets.kogan.com/files/usermanuals/KASMABIDETA_UG_v2.pdf  
OEM:               Tejjer https://tejjer.en.alibaba.com/productgrouplist-825684272/Australia_market.html

## Solution Overview:
* Control funtionality is the same as the app.
* The Tuya WR3 wifi module is totally removed and replaced with an ESP of choice and re-attached to the MCU using a 3-wire JST connector in the same manner as the existing one.  
* Communication is similar to an air conditioner remote and is one way only (cannot read any actual states, commands/states are "optimistic").  
* The ESP sends Pronto commands to the MCU over a single wire. The protocol was reverse engineered and includes checksum generation.

## Details:
* Some Bidets have a "traditional remote". It seems likely this bidet had a remote and a reciever set-up and the wifi remote just uses the same MCU port and protocol. So quite a half-arsed "smart" device;)


## Wiring
| **Wire Colour** | **Function** | **Description**                         |
|-----------------|--------------|-----------------------------------------|
| **Red**         | 5V           | Power to the wifi module                |
| **Black**       | Ground       | Ground                                  |
| **Blue**        | TX           | Data transfer from wifi module to MCU.  |



Example:

```
todo: my_yaml

```
