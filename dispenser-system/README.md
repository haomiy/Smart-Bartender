# Dispenser-System
Dispense beverage type and amount based on external command

## Table of Contents
- [System Overview](#system-overview)
- [Hardware Setup](#hardware-setup)
- [Commands](#commands)
  * [Sent to the system](#sent-to-the-system)
  * [Received from the system](#received-from-the-system)
  
## System Overview
This system dispenses beverages of differing type and amount based on external command.   

The system uses **UART** at baud rate of **9600** to transmit data.   

All commands sent to this system will be 5 bytes, as will be explained later in the [Commands](#commands) section   
All commands received from this system will be 6 bytes, as will be explained later in the [Commands](#commands) section   

## Hardware Setup
> TODO - Not yet complete

## Commands
The following \<Byte>s will be referenced later in this section  

\<Byte> Name | \<Byte> Value | \<Byte>Description
-------------|---------------|-------------------
Start        | 0x55          | The start byte of any message sent or received
End          | 0xAA          | The end byte of any message sent or received
Slot         | [Variable]    | Selection of a specific drink
Volume       | [Variable]    | Volume in milliliters
Response     | [Variable]    | Response of the system. See below.
ACK          | 0x01          | Acknowledged. Previous command successful.
NAK          | 0x00          | Not acknowledged. Previous command failed.

### Send to the system
All commands sent to the system must be 5 bytes, and in   
the format of **\<Start> \<Slot> \<Volume High Byte> \<Volume Low Byte> \<End>**   

Otherwise, it will be ignored.   

\<Start> must be 0x55, although this can be changed if needed.   
\<Slot> represents the selection of one of the drinks.   
Currently, \<Slot> must be in range of 0x00 and 0x02 inclusive, since there are only three possible drinks to choose from.   
\<Volume High Byte> and \<Volume Low Byte> represent the volume in milliliters of the   
liquid to be poured.   
The formula is given by: **\<Volume High Byte> << 8 | \<Volume Low Byte>**   
\<End> must be 0xAA, although this can be changed if needed.   

### Received from the system
All commands received from the system must be 6 bytes, and in   
the format of **\<Start> \<Response> \<Slot> \<Volume High Byte> \<Volume Low Byte> \<End>**   

\<Start> will be 0x55, although this can be changed if needed.   
\<Response> will either be ACK or NAK, to indicate success or failure.   
\<Slot>, \<Volume High Byte>, and \<Volume Low Byte> will be the same ones sent to the system, for verification purposes.   
\<End> will be 0xAA, although this can be changed if needed.   
