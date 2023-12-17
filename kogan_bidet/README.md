# Kogan SmarterHome™ Smart Antibacterial Wash & Dry Electric Bidet Toilet Seat

## The Future Is Now!!
Finally you can stop your toilet from phoning foreign governments and get it out of the cloud and back down to earth!!!

![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/56a7c8f8-5434-4a4c-9929-c24bfa4aeb5f)
 
This yaml provides ESPHome support for the Kogan SmarterHome™ Smart Antibacterial Wash & Dry Electric Bidet Toilet Seat.

## Product Details
Name:      KOGAN SMARTERHOME™ SMART ANTIBACTERIAL WASH & DRY ELECTRIC BIDET TOILET SEAT  
Listing:   https://www.kogan.com/au/buy/kogan-smarterhome-smart-antibacterial-wash-dry-electric-bidet-toilet-seat/  
Code:      KASMABIDETA  
Manual:    https://assets.kogan.com/files/usermanuals/KASMABIDETA_UG_v2.pdf  
OEM:       Tejjer https://tejjer.en.alibaba.com/productgrouplist-825684272/Australia_market.html  

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
* Some Bidets have a "traditional remote". It seems likely this bidet was originally designed with a more tradtional remote and reciever set-up and the wifi remote just uses the same MCU port and protocol. So quite a half-arsed "smart" device;)
* Tip: While you have it open, cover the buzzer with a bit of tape etc if you find the beeps too loud. I used a bit of Sugru, which actually makes it barely audible. 
* Protocol decoding: See table in .yaml file.

## Wiring
| **Wire Colour** | **Function** | **Description**                         |  **ESP Wiring**  |
|-----------------|--------------|-----------------------------------------|------------------|
| **Red**         | 5V           | Power to the wifi module                | 5V               |
| **Black**       | Ground       | Ground                                  | Ground           |
| **Blue**        | TX           | Data transfer from wifi module to MCU.  | GPIO             |

## Wifi Module Assembly Overview:  
![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/ab443657-ad65-4f80-bbfc-16eceab5a957)

## Teardown
![image](https://github.com/OkhammahkO/esphome_my_custom_components/assets/43776617/f63378d9-b8c1-418d-99a5-042ef7a8c15d)

**Parts list:**
1. An **ESP32** (or ESP8266). I used an S2 mini I had spare.
2. **JST connector:** I don’t know the specific type; I just grabbed one that matched from a kit I got a while back. To confirm the size/type, you may need to pull out the Tuya wifi assembly and measure up.
3. **Wire:** I really like working with flexible silicone wire.
4. **Small zip-ties:** (to replace the ones you’ll cut inside the loo). Optional but probably a good idea.

**Instructions:**
1. **Build your new ESPHome wifi assembly**
   - Connect the wires to the ESP (soldering recommended) and crimp the JST connection on the other end. Match the wire order and JST orientation to the original.
   - **A bit of hot glue may be a good idea** to help with some wire strain relief.
   - Probably you could buy one instead which might be easier if you don’t have a kit and crimper on hand.
   - I also used a male JST to build a little JST to Dupont adapter for sniffing and powering the Tuya module. **You shouldn’t really need one of those though.**

2. **Print a new enclosure (optional). TODO: Publish 3d print model.**

3. **Flash it with the ESPHome firmware.**
   - Follow the usual process.
   - You can use the USB connector on your ESP while doing this and to check it seems to be working ok before you install it (check the logs look ok when you change user inputs).
   - Later when installed, you power and ground it via the JST and respective pins.

4. **Open the bidet, remove the old wifi assembly, and install the new one.**
   - To open the bidet, there are two screws underneath that come out, and then you’ll see some clip things along the back edge to help keep it in. If you pry up near these clips carefully, the base will pop off/out (say with a flat head screwdriver or pry tools).
   - Be careful not to put too much stress on the various wires as you remove the base and orient it so you have access. Should all be fine, just be a little careful.
   - Locate the Tuya module and remove the screw. Locate the JST port on the MCU and remove it. Note the wire routing. Clip a few zip ties then totally remove it.
   - Install the new one by reversing steps above.

## FAQs:
1.	**This is weird. Why would you even want to automate a smart bidet?**
   - Because you can.
   - To optimise power management.
   - You can set bidet temperatures you want (water, seat) based on ambient temperatures of your bathroom – heat more when it’s needed.
   - Dunny light on when you walk in the bathroom at night could be handy.


Example:

```
todo: my_yaml

```
