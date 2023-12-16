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
* Communication is similar to an air conditioner remote and is one way only. You cannot read any actual states. Commands and states are "optimistic".
* The ESP sends Pronto commands to the MCU over a single (blue) wire. The protocol was reverse engineered and includes checksum generation. 
* You can't use the Tuya App after you do this - you just build whatever Home Assistant frontend you want for your backend.
* The Tuya WR3 wifi module assembly is removed and replaced with an ESP of choice and re-attached to the MCU using a 3-wire JST connector in the same manner as the existing one.
* A benefit of doing it this way is that the solution is reversable (you can reinstall the Tuya module), and also you can use the Tuya module "on the bench" to further explore potentially undiscovered parts of the protocol.   

![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/9b7b1ba4-1bef-4b2c-b360-266b64056bd5)


## Details:
* Some Bidets have a "traditional remote". It seems likely this bidet had a remote and a reciever set-up and the wifi remote just uses the same MCU port and protocol. So quite a half-arsed "smart" device;)
* Tip: While you have it open, cover the buzzer with a bit of tape etc if you find the beeps too loud.

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

## Protocol
# Kogan Smart Bidet Pronto Protocol
 ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
| Function                          | Code Name                             | Bits    | Count | Constant | Checksum | Comment
|-----------------------------------|---------------------------------------|---------|-------|----------|----------|----------------------------------------------------------------------------------------------------------
| Pronto Preamble                   | PREAMBLE_BITS_1_TO_4                  | 01-04   | 4     | Yes      | No       | Raw data, Carrier frequency (38kHz), 51 Burst Pairs in Sequence #1, No Sequence #2 (Repeat).
| Lead in burst pairs               | LEAD_IN_BURST_PAIRS_BITS_5_TO_8       | 05-08   | 4     | Yes      | No       | Assumed function
| Address                           | ADDRESS_BITS_9_TO_24                  | 09-24   | 16    | Yes      | Yes      | Assumed. Appears to be constant
| Idle Mode                         | IDLE_MODE_BITS_25_AND_26              | 25-26   | 2     | No       | Yes      | ON if rear, front, dry NOT enabled (after stop button). Required to start some of the presets (Child, Super, etc)
| UNKNOWN_BITS_27_TO_30             | UNKNOWN_BITS_27_TO_30                 | 27-30   | 4     | Yes      | Yes      | Unknown. Always 0.
| Cleaning Mode                     | CLEANING_MODE_BITS_31_TO_40           | 31-40   | 10    | No       | Yes      | self_clean, rear, female, dry, auto_wash. Presets not in app: powerful_wash, child, lady_care, rear_massage, female_massage
| Spray Water Temp                  | WATER_TEMP_BITS_41_TO_48              | 41-48   | 2     | No       | Yes      | Four levels. Level 1 is room temp (no heating). L2 = Target temp 33°C (per manual), L3 = 36°C, L4 = 39°C
| Light                             | LIGHT_49_AND_50                       | 49-50   | 2     | No       | Yes      | Bowl LED On or Off
| UNKNOWN_BITS_51_AND_52            | UNKNOWN_BITS_51_AND_52                | 51-52   | 2     | No       | Yes      | Unknown. Always 0.
| Cleaning Position                 | CLEANING_POSITION_BITS_53_TO_56       | 53-56   | 4     | No       | Yes      | 4 positions of cleaning wand extension. Works for Rear. Can't recall if tested for female.
| Seat Temp                         | SEAT_TEMP_BITS_57_TO_64               | 57-64   | 8     | No       | Yes      | Four levels. Level 1 is room temp (no heating). L2 = Target temp 33°C (per manual), L3 = 36°C, L4 = 39°C
| UNKNOWN_BITS_65_TO_68             | UNKNOWN_BITS_65_TO_68                 | 65-68   | 4     | No       | Yes      | Unknown. Always 0
| Cleaning Pressure or Drying temp  | CLEAN_PRESS_OR_DRY_TEMP_BITS_69_TO_72 | 69-72   | 4     | No       | Yes      | If in drying mode then changes air temp, if in cleaning mode then changes water pressure
| UNKNOWN_BITS_73_TO_76             | UNKNOWN_BITS_73_TO_76                 | 73-76   | 6     | No       | Yes      | Unknown. Always 0
| ECO Mode                          | ECO_MODE_BITS_77_AND_78               | 77-78   | 2     | No       | Yes      | Turn on/off power saving routines
| UNKNOWN_BITS_79_TO_84             | UNKNOWN_BITS_79_TO_84                 | 79-84   | 6     | No       | Yes      | Unknown. Always 0
| Deodorize                         | DEODORIZE_MODE_BITS_85_AND_86         | 85-86   | 2     | No       | Yes      | Turn on/off deodorizer
| UNKNOWN_BITS_87_AND_88            | UNKNOWN_BITS_87_AND_88                | 87-88   | 2     | No       | Yes      | Unknown. Always 0
| Checksum (calculated)             | CHECKSUM_BITS_89_TO_104               | 89-104  | 16    | No       | No       | Sum of command bits, then modulo 256
| Lead out burst pairs              | LEAD_OUT_BURST_PAIRS_BITS_105_AND_106 | 105-106 | 2     | Yes      | No       | Assumed function
                                                                            |TOTAL    | 106

Example:

```
todo: my_yaml

```
