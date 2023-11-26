// #pragma once

// #include "esphome/components/climate_ir/climate_ir.h"
#include <array>
#include <cstdint>

namespace esphome
{
  namespace kogan_bidet
  {
    // Function               | Bits    | Count | Constant | In Checksum | Comment
    // -----------------------|---------|-------|----------|-------------|----------------------------------------------------
    // Pronto Preamble        | 01-04   |    4  | Yes      | No          |
    // Lead in burst pairs    | 05-08   |    4  | Yes      | No          | Assumed function
    // Address                | 09-24   |   16  | Yes      | Yes         | Appears to be constant
    // Commands               | 25-88   |   64  | No       | Yes         | Included in checksum
    // Checksum               | 89-104  |   16  | No       | No          | Sum of command bits, then modulo 256
    // Lead out burst pairs   | 105-106 |    2  | Yes      | No          | Assumed function

    // Pronto Preamble
    const std::array<uint8_t, 8> PREAMBLE_BITS_1_TO_4 = {0x00, 0x6D, 0x33, 0x00}; // Raw data, Carrier frequency (38031.13 Hz), 51 Burst Pairs in Sequence #1, No Sequence #2 (Repeat).

    // Lead-in Burst Pairs
    const std::array<uint8_t, 8> LEAD_IN_BURST_PAIRS_BITS_5_TO_8 = {0x74, 0x75, 0x74, 0xAA};

    // Address
    const std::array<uint8_t, 16> ADDRESS_BITS_9_TO_24 = {0x14, 0x40, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x40, 0x14, 0x40};

    // Lead out burst pair
    const std::array<uint8_t, 2> LEAD_OUT_BURST_PAIRS_BITS_105_AND_106 = {0x14, 0x81};

    // Command Structure
    // | Command Short Name                | Bit Positions | Bit Count | Description
    // | ----------------------------------| --------------| --------- | ----------------------------------------------
    // | Idle Mode                         | 25-26         | 2         | ON if rear, front, dry NOT enabled (after stop button). Required to start some of the presets (Child, Super, etc)
    // | UNKNOWN_BITS_27_TO_30             | 27-30         | 4         | Unknown. Always 1. Could relate to presets, power, or seated (not in app but avaible in scenes?)
    // | Cleaning Mode                     | 31-40         | 10        | self_clean, rear, female, dry, auto_wash. Presets not in app: powerful_wash, child, lady_care, rear_massage, female_massage
    // | Spray Water Temp                  | 41-48         | 2         | Four levels. Level 1 is room temp (no heating). L2 = Target temp 33°C (per manual), L3 = 36°C, L4 = 39°C
    // | Light                             | 49-50         | 2         | Bowl LED On or Off
    // | UNKNOWN_BITS_51_AND_52            | 51-52         | 2         | Unknown. Always 0.
    // | Cleaning Position                 | 53-56         | 4         | 4 postions of cleaning wand extention. Works for Rear. Can't recall if tested for female.
    // | Seat Temp                         | 57-64         | 8         | Four levels. Level 1 is room temp (no heating). L2 = Target temp 33°C (per manual), L3 = 36°C, L4 = 39°C
    // | UNKNOWN_BITS_65_TO_68             | 65-68         | 4         | Unknown. Always 0
    // | Cleaning Pressure or Drying temp  | 69-72         | 4         | If in drying mode then changes air temp, if in cleaning mode then changes water pressure
    // | UNKNOWN_BITS_73_TO_76             | 73-76         | 6         | Unknown. Always 0
    // | ECO Mode                          | 77-78         | 2         | Turn on/off power saving routines
    // | UNKNOWN_BITS_79_TO_84             | 79-84         | 6         | Unknown. Always 0
    // | Deodorize                         | 85-86         | 2         | Turn on/off deoderiser
    // | UNKNOWN_BITS_87_AND_88            | 87-88         | 2         | Unknown. Always 0

    // Idle Mode
    const std::array<uint8_t, 2> IDLE_MODE_BITS_25_AND_26_ON = {0x14, 0x40};
    const std::array<uint8_t, 2> IDLE_MODE_BITS_25_AND_26_OFF = {0x14, 0x16};

    // UNKNOWN_BITS_27_TO_30
    const std::array<uint8_t, 4> UNKNOWN_BITS_27_AND_28 = {0x14, 0x40, 0x14, 0x16};

    // Cleaning Mode
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_REAR = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_DRY = {0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_FEMALE = {0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x40};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_AUTO = {0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16};
    const std::array<uint8_t, 10> CLEANING_MODE_BITS_31_TO_40_SELF_CLEAN = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40};

    // Spray Water Temperature Level
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_1 = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_2 = {0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_3 = {0x14, 0x16, 0x14, 0x40, 0x14, 0x40, 0x14, 0x40};
    const std::array<uint8_t, 8> WATER_TEMP_BITS_41_TO_48_LEVEL_4 = {0x14, 0x40, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16};

    // LED
    const std::array<uint8_t, 2> LIGHT_49_AND_50_ON = {0x14, 0x40};
    const std::array<uint8_t, 2> LIGHT_49_AND_50_OFF = {0x14, 0x16};

    // UNKNOWN_BITS_51_AND_52
    const std::array<uint8_t, 2> UNKNOWN_BITS_51_AND_52 = {0x14, 0x16};

    // Cleaning Position
    const std::array<uint8_t, 8> CLEANING_POSITION_BITS_53_TO_56_POS_1 = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> CLEANING_POSITION_BITS_53_TO_56_POS_2 = {0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> CLEANING_POSITION_BITS_53_TO_56_POS_3 = {0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> CLEANING_POSITION_BITS_53_TO_56_POS_4 = {0x14, 0x40, 0x14, 0x40, 0x14, 0x40, 0x14, 0x40};

    // Seat Temperature
    const std::array<uint8_t, 8> SEAT_TEMP_BITS_57_TO_64_LEVEL_1 = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> SEAT_TEMP_BITS_57_TO_64_LEVEL_2 = {0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> SEAT_TEMP_BITS_57_TO_64_LEVEL_3 = {0x14, 0x16, 0x14, 0x40, 0x14, 0x40, 0x14, 0x40};
    const std::array<uint8_t, 8> SEAT_TEMP_BITS_57_TO_64_LEVEL_4 = {0x14, 0x40, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16};

    // UNKNOWN_BITS_27_AND_28
    const std::array<uint8_t, 4> UNKNOWN_BITS_65_TO_68 = {0x14, 0x16, 0x14, 0x16};

    // Cleaning Pressure or Drying Temp
    const std::array<uint8_t, 8> CLEAN_PRESS_OR_DRY_TEMP_BITS_69_TO_72_LEVEL_1 = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> CLEAN_PRESS_OR_DRY_TEMP_BITS_69_TO_72_LEVEL_2 = {0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> CLEAN_PRESS_OR_DRY_TEMP_BITS_69_TO_72_LEVEL_3 = {0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16};
    const std::array<uint8_t, 8> CLEAN_PRESS_OR_DRY_TEMP_BITS_69_TO_72_LEVEL_4 = {0x14, 0x40, 0x14, 0x40, 0x14, 0x40, 0x14, 0x40};

    // UNKNOWN_BITS_73_TO_76
    const std::array<uint8_t, 4> UNKNOWN_BITS_73_TO_76 = {0x14, 0x16, 0x14, 0x16};

    // Eco Mode (Energy saving)
    const std::array<uint8_t, 2> IDLE_MODE_BITS_77_AND_78_ON = {0x14, 0x40};
    const std::array<uint8_t, 2> IDLE_MODE_BITS_77_AND_78_OFF = {0x14, 0x16};

    // UNKNOWN_BITS_79_TO_84
    const std::array<uint8_t, 6> UNKNOWN_BITS_79_TO_84 = {0x14, 0x16, 0x14, 0x16, 0x14, 0x16};

    // Deodorise
    const std::array<uint8_t, 2> DEODORISE_MODE_BITS_85_AND_86_ON = {0x14, 0x40};
    const std::array<uint8_t, 2> DEODORISE_MODE_BITS_85_AND_86_OFF = {0x14, 0x16};

    // UNKNOWN_BITS_87_AND_88
    const std::array<uint8_t, 2> UNKNOWN_BITS_87_AND_88 = {0x14, 0x16};

    // // State Frame size
    // const uint8_t DAIKIN_STATE_FRAME_SIZE = 19;

    // class DaikinClimate : public climate_ir::ClimateIR
    // {
    // public:
    //   DaikinClimate()
    //       : climate_ir::ClimateIR(DAIKIN_TEMP_MIN, DAIKIN_TEMP_MAX, 1.0f, true, true,
    //                               {climate::CLIMATE_FAN_AUTO, climate::CLIMATE_FAN_LOW, climate::CLIMATE_FAN_MEDIUM,
    //                                 climate::CLIMATE_FAN_HIGH},
    //                               {climate::CLIMATE_SWING_OFF, climate::CLIMATE_SWING_VERTICAL,
    //                                 climate::CLIMATE_SWING_HORIZONTAL, climate::CLIMATE_SWING_BOTH}) {}

    // protected:
    //   // Transmit via IR the state of this climate controller.
    //   void transmit_state() override;
    //   uint8_t operation_mode_();
    //   uint16_t fan_speed_();
    //   uint8_t temperature_();
    //   // Handle received IR Buffer
    //   bool on_receive(remote_base::RemoteReceiveData data) override;
    //   bool parse_state_frame_(const uint8_t frame[]);
    // };

  } // namespace kogan_bidet
} // namespace esphome