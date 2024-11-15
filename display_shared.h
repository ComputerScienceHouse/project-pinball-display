#ifndef __PCP_DISPLAY_SHARED_H
#define __PCP_DISPLAY_SHARED_H

#define COMM_MAGIC 0x0702

typedef enum: unsigned short {
  GAME_ADD_PLAYER = 0x0001,
  GAME_START = 0x0003,
  GAME_STATUS_UPDATE = 0x0004,
  END_OF_BALL = 0x0005,
  BALL_PUSHED = 0x0006,
  SCOOP_LIGHT_LIT = 0x0007,
  MULTIBALL_JACKPOT = 0x0008,
  HURRY_UP = 0x0009,
  THING_HIT = 0x000a,
  EXTRA_BALL_GOT = 0x000b,
  SKILL_SHOT = 0x000c,
  BALL_SAVE = 0x000d,
  TILT_WARNING = 0x000e,
  TILT = 0x000f,
} comm_type;

typedef enum: unsigned char {
  MODE_NONE = 0,
  YOU_DID_WHAT = 1,
  OPCOMMATHON = 2,
  HOUSE_MEETING = 4,
  FINALS = 8,
} Mode;


typedef enum: unsigned char {
  MULTI_NONE = 0,
  BAGELS = 1,
  PARTY_BUTTON = 2,
  PCP = 4,
} Multiball;

typedef struct game_add_player {
  unsigned char number_of_players;
} game_add_player;

typedef struct {
  unsigned char number_of_players;
} game_start;

typedef struct {
  unsigned long long player_1_score;
  unsigned long long player_2_score;
  unsigned long long player_3_score;
  unsigned long long player_4_score;
  unsigned char number_of_players;
  unsigned char current_player;
} game_status_update;

typedef struct {
  unsigned short drinks_dropped;
  unsigned short devcade_games;
  unsigned short imagine_projects;
  unsigned short bonus_multiplier;
} end_of_ball;

typedef struct {
  Multiball multiball;
  unsigned char balls_pushed;
} ball_pushed;

typedef enum {
  MODE = 0,
  MULTIBALL = 1,
  EXTRA_BALL = 2,
  MYSTERY = 3,
} scoop_light_type;

typedef union {
  Mode mode;
  Multiball multiball;
  char none;
} scoop_light_info;

typedef struct {
  scoop_light_type scoop_light_type;
  scoop_light_info scoop_light_info;
} scoop_light;

typedef struct {
  Multiball current_multiball;
} multiball_jackpot;
// Add enum maybe?
typedef struct {
  unsigned short which_hit;
} thing_hit;

#endif
