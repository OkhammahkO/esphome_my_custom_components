# Kogan SmarterHome™ Smart Antibacterial Wash & Dry Electric Bidet Toilet Seat

## The Future Is Now!!
Finally you can stop your toilet from phoning foreign governments and get it out of the cloud and back down to earth!!!

![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/12326551-d852-4b70-8c4d-cae6e001090d)
 
This yaml provides ESPHome support for the Kogan SmarterHome™ Smart Antibacterial Wash & Dry Electric Bidet Toilet Seat.

## Product Details
Product Name:      KOGAN SMARTERHOME™ SMART ANTIBACTERIAL WASH & DRY ELECTRIC BIDET TOILET SEAT  
Product Listing:   https://www.kogan.com/au/buy/kogan-smarterhome-smart-antibacterial-wash-dry-electric-bidet-toilet-seat/  
Product Code:      KASMABIDETA  
Product Manual:    https://assets.kogan.com/files/usermanuals/KASMABIDETA_UG_v2.pdf  
OEM:               Tejjer https://tejjer.en.alibaba.com/productgrouplist-825684272/Australia_market.html  

## Solution Overview:
* Control funtionality is the same as the app.
* Solution removes all Tuya communication - the device is yours.
* Communication is similar to an air conditioner remote and is one way only. This means commands and states are "optimistic".
* The ESP sends Pronto commands to the MCU over a single (blue) wire. The protocol was reverse engineered and includes checksum generation. 
* You can't use the Tuya App after you do this - you just build whatever Home Assistant frontend you want for your backend.
* The Tuya WR3 wifi module assembly is removed and replaced with an ESP of choice and re-attached to the MCU using a 3-wire JST connector in the same manner as the existing one.
* A benefit of doing it this way is that the solution is reversable (you can reinstall the Tuya module), and also you can use the Tuya module "on the bench" to further explore potentially undiscovered parts of the protocol.   

![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/9b7b1ba4-1bef-4b2c-b360-266b64056bd5)


## Details:
* Some Bidets have a "traditional remote". It seems likely this bidet had a remote and a reciever set-up and the wifi remote just uses the same MCU port and protocol. So quite a half-arsed "smart" device;)
* Tip: While you have it open, cover the buzzer with a bit of tape etc if you find the beeps too loud.
* Protocol decoding: See table in .yaml file.

## Wiring
| **Wire Colour** | **Function** | **Description**                         |  **ESP Wiring**  |
|-----------------|--------------|-----------------------------------------|------------------|
| **Red**         | 5V           | Power to the wifi module                | 5V               |
| **Black**       | Ground       | Ground                                  | Ground           |
| **Blue**        | TX           | Data transfer from wifi module to MCU.  | GPIO             |

## Wifi module assembly:  
![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/040e41af-f24a-46bb-90e7-a5dbdb355b93)


## Teardown
![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/f63378d9-b8c1-418d-99a5-042ef7a8c15d)

Example:

```
todo: my_yaml

```
