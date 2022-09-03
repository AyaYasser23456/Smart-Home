/*
   SmartHome.c

   Created: 7/5/2022 12:34:53 AM
   Author : Smart Home Team
*/

#define FIRST_PAGE			'0'
#define ADMIN_LOGIN_PAGE    '1'
#define USER_LOGIN_PAGE     '2'
#define WELCOME				 0
#define ADMIN_SECOND_PAGE    1
#define USER_SECOND_PAGE     2
#define ADMIN_THIRD_PAGE     3
#define ADMIN_FOURTH_PAGE    4
#define IDLE_STATE			 5
#define AdminMode			 1
#define UserMode			 2


#include "Led.h"
#include "Buzzer.h"
#include "PushButton.h"
#include "Lcd.h"
#include "KeyPad.h"
#include "Servo.h"
#include "DcMotor.h"
#include "Lm35.h"
#include "Eeprom.h"
#include "Relay.h"
#include "Hc05.h"

//#include "ExtInt.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void InputID    (u8* ID, u8 Mode);
void InputPassword  (u8* Password, u8 Mode);
u8 AdminLogin (u8* ID, u8* Password);
void AddUser (u8* ID, u8* Password);
u8 UserLogin ( u8* ID, u8* Password);
void CheckEEPROM(void);
void DeleteUser (u8 NumberOfUsers, u8* ID);
void DeleteAll (void);
void ACSwitch (u8* ACOpened);
void SwitchDoor (u8* DoorOpened);
void RelaySwitch(u8* RelayOpened);
void AppInit(void);
void CloseTheDoor(void);
void WelcomingMsg(void);
void A_Main_ExtInt0Exc (void);
void CheckAC(u8 ACState);
void CheckDoor(u8 DoorState);
void CheckRelay(u8 RelayState);
void Reset(u8* ACState, u8* DoorState, u8* RelayState);

u8 AppState = WELCOME;

/************************************************************************/
/*  Admin Password is 1234
  Admin UserName is 123
  Admin Location is @ 101 byte address page 1             */
/************************************************************************/

int main ()
{
  H_Lcd_Init();
  H_KeyPad_Init();
  H_Eeprom_Init();
  H_DcMotor_Init();
  H_Lm35_Init();
  H_Servo_Init();
  H_Led_Init(LED_0);
  H_Led_Init(LED_1);
  H_Buzzer_Init();
  H_PushButton_Init();
  H_Relay_Init();
  H_Hc05_Init();

  /* Initiate the UserID and Password */
  //Remove two below comments when first use of code
  //  DeleteAll();
  //  AppInit();

  char NumberOfUsers = 0;

  NumberOfUsers = H_Eeprom_Read(0, 100);
  u8 UserID   [3] = {0, 0, 0};
  u8 UserPassword [4] = {0, 0, 0, 0};
  u8 KeyPressed = 0;
  u8 Trails = 0;
  u8 DoorState = 0;
  u8 ACState = 0;
  u8 RelayState = 0;
  u8 BluetoothData = 0;

  while (1)
  {
    switch (AppState)
    {
      case WELCOME :
        WelcomingMsg();
        AppState = FIRST_PAGE;
        break;
      case FIRST_PAGE:
        H_Lcd_Clear();
        H_Lcd_WriteString("    Welcome     ");
        H_Hc05_SendString("Choose user using Keypad");
        H_Lcd_GoTo(1, 0);
        H_Lcd_WriteString("1:Admin 2:User");
        H_Hc05_SendString("1:Admin 2:User");
        KeyPressed = H_KeyPad_Read();
        while (!KeyPressed)
        {
          KeyPressed = H_KeyPad_Read();
          if (KeyPressed == '1')
          {
            AppState = ADMIN_LOGIN_PAGE;
          }
          else if (KeyPressed == '2')
          {
            AppState = USER_LOGIN_PAGE;
          }
          else
          {
            /*DO NOTHING*/
          }

        }
        break;

      case ADMIN_LOGIN_PAGE:
        Trails = 0;
        H_Lcd_Clear();
        H_Hc05_SendString("Welcome Admin");
        H_Lcd_WriteString("Welcome Admin");
        _delay_ms(1000);
        H_Lcd_Clear();
        H_Lcd_GoTo(0, 0);
        H_Lcd_WriteString("Admin Mode");
        H_Lcd_GoTo(1, 0);
        H_Lcd_WriteString("Use Bluetooth");
        H_Hc05_SendString("Use Bluetooth");
        _delay_ms(3000);

        while (Trails < 3)
        {
          H_Hc05_SendString("Enter Username");
          InputID(UserID, AdminMode);
          H_Hc05_SendString("Enter Password");
          InputPassword(UserPassword, AdminMode);

          if (AdminLogin(UserID, UserPassword) == 0)
          {
            AppState = ADMIN_SECOND_PAGE;
            break;
          }
          else
          {
            Trails++;
            if (Trails == 3)
            {
              H_Buzzer_On();
              CloseTheDoor();
              KeyPressed = H_PushButton_Read();
              while (1)
              {
                if (H_PushButton_Read() == PRESSED)
                {
                  _delay_ms(80);
                  if (H_PushButton_Read() == PRESSED)
                  {
                    while (H_PushButton_Read() == PRESSED);
                    H_Buzzer_Off();
                    AppState = WELCOME;
                    break;
                  }
                }
              }
            }
          }
        }
        Trails = 0;
        break;

      case USER_LOGIN_PAGE:
        Trails = 0;
        H_Lcd_Clear();
        H_Lcd_WriteString("Welcome User");
        _delay_ms(1000);
        while (Trails < 3)
        {
          H_Lcd_Clear();
          H_Lcd_WriteString("Enter Username");
          InputID(UserID, UserMode);
          H_Lcd_Clear();
          H_Lcd_WriteString("Enter Password");
          InputPassword(UserPassword, UserMode);
          u8 LoginResult = UserLogin(UserID, UserPassword);

          if (LoginResult == 0)
          {
            AppState = USER_SECOND_PAGE;
            break;
          }
          else if (LoginResult == 2)
          {
            AppState = FIRST_PAGE;
            break;
          }
          else if (LoginResult == 1)
          {
            Trails++;
            if (Trails == 3)
            {
              H_Buzzer_On();
              CloseTheDoor();
              H_Lcd_Clear();
              KeyPressed = H_PushButton_Read();
              while (1)
              {
                if (H_PushButton_Read() == PRESSED)
                {
                  _delay_ms(80);
                  if (H_PushButton_Read() == PRESSED)
                  {
                    while (H_PushButton_Read() == PRESSED);
                    H_Buzzer_Off();
                    AppState = WELCOME;
                    break;
                  }
                }
              }
            }
          }
        }
        Trails = 0;
        break;

      case ADMIN_SECOND_PAGE:
        BluetoothData = 0;
        BluetoothData = H_Hc05_Rec();
        switch (BluetoothData)
        {
          // A ->  A/C Switch
          case 'A':    ACSwitch(&ACState);                          break;
          // B ->  Add user
          case 'B':
            H_Lcd_Clear(); H_Lcd_WriteString("Use KeyPad");
            H_Hc05_SendString("Use KeyPad");
            _delay_ms(3000);
            InputID(UserID, UserMode);
            InputPassword(UserPassword, UserMode);
            AddUser(UserID, UserPassword);                       break;
          // C -> Remove user
          case 'C':
            NumberOfUsers = H_Eeprom_Read(0, 100);
            H_Lcd_Clear(); H_Lcd_WriteString("Use Bluetooth");
            H_Hc05_SendString("Use Bluetooth"); _delay_ms(3000);
            InputID(&UserID, AdminMode);
            DeleteUser(NumberOfUsers, UserID);                     break;
          // D -> Door Switch
          case 'D':   SwitchDoor(&DoorState);                         break;
          // R -> Relay Switch
          case 'R':   RelaySwitch(&RelayState);                       break;
          // U -> User Mode
          case 'U':     AppState = USER_LOGIN_PAGE;                      break;
          // S -> Resut Mode
          case 'S': Reset(&ACState, &DoorState, &RelayState);  AppState = WELCOME;         break;
          //I -> Idle State (OK)
          case 'I':     AppState = IDLE_STATE;                       break;
          default:                                        break;
        }
        break;
      case IDLE_STATE:
        BluetoothData = H_Hc05_Rec();
        while (!BluetoothData)
        {
          BluetoothData = H_Hc05_Rec();
          CheckAC(ACState);
          CheckRelay(RelayState);
          CheckDoor(DoorState);
        }
        AppState = WELCOME;

        break;

      case USER_SECOND_PAGE :
        H_Lcd_Clear();
        H_Lcd_WriteString(" 1:Switch Relay ");
        H_Lcd_GoTo(1, 0);
        H_Lcd_WriteString("2:AcSwitch  3:OK");
        KeyPressed = H_KeyPad_Read();
        while (!KeyPressed)
        {
          KeyPressed = H_KeyPad_Read();
          if (KeyPressed == '1')
          {
            RelaySwitch(&RelayState);
          }
          else if (KeyPressed == '2')
          {
            ACSwitch(&ACState);
          }
          else if (KeyPressed == '3')
          {
            AppState = IDLE_STATE;
          }
        }
        break;
    }

  }
  return 0;
}

void AddUser (u8* ID, u8* Password)
{
  u8 NumberOfUsers = H_Eeprom_Read(0, 100);
  if (NumberOfUsers < 10)
  {
    u8 Counter = 0, UserLocation  = 0;

    if (NumberOfUsers > 0)
    {
      u8 WrongEntry = 0;

      for (; Counter < NumberOfUsers; Counter++)
      {

        UserLocation = (Counter * 7);
        u8 Check = 0, EEPROMData = 0, EEPROMDataLocation = 0, ValidEntries = 3;

        for (; Check < 3; Check++)
        {
          EEPROMDataLocation = UserLocation + Check;
          EEPROMData = H_Eeprom_Read(0, EEPROMDataLocation);
          if (ID[Check] == EEPROMData )
          {
            ValidEntries--;
          }

        }

        if (ValidEntries == 0)
        {
          /*print on LCD invalid username*/
          WrongEntry ++;
          H_Lcd_Clear();
          H_Lcd_WriteString("Invalid Username");
          H_Hc05_SendString("Invalid Username");
          _delay_ms(500);
        }
      }


      if (WrongEntry == 0)
      {
        /*print on LCD valid entry*/
        H_Lcd_Clear();
        H_Lcd_WriteString("Valid Entry");
        H_Hc05_SendString("Valid Entry");
        _delay_ms(500);
        u8 Check = 0, EEPROMDataLocation = 0;
        UserLocation = NumberOfUsers * 7;
        for (; Check < 3; Check++)
        {
          EEPROMDataLocation = UserLocation + Check;
          H_Eeprom_Write(ID[Check], 0, EEPROMDataLocation);
        }

        for (Check = 0; Check < 4; Check++)
        {
          EEPROMDataLocation = UserLocation + Check + 3;
          H_Eeprom_Write(Password[Check], 0, EEPROMDataLocation);
        }
        NumberOfUsers++;
        H_Eeprom_Write(NumberOfUsers, 0, 100);

      }
    }
    else /*There isn't any user yet*/
    {
      H_Lcd_Clear();
      H_Lcd_WriteString("Valid Entry");
      _delay_ms(500);
      H_Hc05_SendString("Valid Entry");
      u8 Check = 0, EEPROMDataLocation = 0;
      UserLocation = NumberOfUsers * 7;     /*UserLocation = 0*/
      for (; Check < 3; Check++)
      {
        EEPROMDataLocation = UserLocation + Check;
        H_Eeprom_Write(ID[Check], 0, EEPROMDataLocation);
      }

      for (Check = 0; Check < 4; Check++)
      {
        EEPROMDataLocation = UserLocation + Check + 3;
        H_Eeprom_Write(Password[Check], 0, EEPROMDataLocation);
      }
      NumberOfUsers++;
      H_Eeprom_Write(NumberOfUsers, 0, 100);

      H_Lcd_Clear();
      H_Lcd_WriteString("User Added");
      H_Hc05_SendString("User Added");
      H_Lcd_GoTo(1, 0);
      H_Lcd_WriteString("No of Users ");
      H_Hc05_SendString("No of Users ");
      H_Lcd_WriteNumber(H_Eeprom_Read(0, 100));
      H_Hc05_Send(H_Eeprom_Read(0, 100));
      _delay_ms(500);
    }
  }
  else /*Number of users is equal or more than 10 users */
  {
    /*Print on LCD you reached max number of users*/
    H_Lcd_Clear();
    H_Lcd_WriteString("Reached max");
    H_Lcd_GoTo(1, 0);
    H_Lcd_WriteString("Number Of Users");
    H_Hc05_SendString("Reached max number Of Users");
    _delay_ms(500);
  }
}

void DeleteUser (u8 NumberOfUsers, u8* ID)
{
  _delay_ms(100);
  H_Lcd_Clear();

  if (NumberOfUsers > 0)
  {
    u8 Counter = 0, UserLocation  = 0, PerfectMatch = 0;

    for (; Counter < NumberOfUsers; Counter++)
    {
      UserLocation = (Counter * 7);
      u8 Check = 0, EEPROMData = 0, EEPROMDataLocation = 0, ValidEntries = 0;

      for (; Check < 3; Check++)
      {
        EEPROMDataLocation = UserLocation + Check;
        EEPROMData = H_Eeprom_Read(0, EEPROMDataLocation);
        if (ID[Check] == EEPROMData )
        {
          ValidEntries++;
        }

      }

      if (ValidEntries == 3)
      {
        /*print on LCD valid username*/
        H_Lcd_WriteString("Valid Username");
        H_Hc05_SendString("Valid Username");
        _delay_ms(200);
        PerfectMatch ++;

      }
      if (PerfectMatch == 1)
      {
        u8 Check = 0, EEPROMDataLocation = 0;
        for (; Check < 3; Check++)
        {
          EEPROMDataLocation = UserLocation + Check;
          EEPROMData = H_Eeprom_Read(0, (EEPROMDataLocation + 7));
          H_Eeprom_Write(EEPROMData, 0, EEPROMDataLocation);
        }
        Check = 0;
        for (; Check < 4; Check++)
        {
          EEPROMDataLocation = UserLocation + Check + 3;
          EEPROMData = H_Eeprom_Read(0, (EEPROMDataLocation + 7));
          H_Eeprom_Write(EEPROMData, 0, EEPROMDataLocation);
        }
      }
    }
    if (PerfectMatch == 1)
    {
      NumberOfUsers--;
      H_Eeprom_Write(NumberOfUsers, 0, 100);
    }

  }

  else
  {
    /*print on LCD There is no any users yet*/

  }

}

u8 AdminLogin (u8* ID, u8* Password)
{
  H_Lcd_Clear();
  u8 ByteAddress = 0, ValidUsername = 0, ValidPassword = 0, Counter = 0, EEPROMData = 0, WrongEntry = 0;
  for (; Counter < 3; Counter++)
  {
    ByteAddress = 101 + Counter;
    EEPROMData = H_Eeprom_Read(0, ByteAddress);
    if (ID[Counter] == EEPROMData)
    {
      ValidUsername++;

    }
    else
    {
      /*Do Nothing*/

      //      H_Lcd_WriteNumber(ValidUsername);
      //      _delay_ms(500);
    }
    //  ValidUsername++;
  }

  for (Counter = 0; Counter < 4; Counter++)
  {
    ByteAddress = 101 + Counter + 3;
    EEPROMData = H_Eeprom_Read(0, ByteAddress);
    if (Password[Counter] == EEPROMData)
    {
      ValidPassword++;
    }
    else
    {
      /*Do Nothing*/
    }

  }
  if ((ValidUsername == 3) && (ValidPassword == 4))
  {
    /*Print on LCD Login Successful*/
    H_Lcd_WriteString("Login Successful");
    H_Hc05_SendString("Login Successful");
    _delay_ms(500);
  }
  else if ((ValidPassword == 4) && (ValidUsername != 3)  )
  {
    /*Print on LCD invalid Username*/
    H_Lcd_WriteString("Invalid Username");
    H_Hc05_SendString("Invalid Username");
    _delay_ms(500);
    WrongEntry++;
  }
  else if ((ValidUsername == 3) && (ValidPassword != 4))
  {
    /*Print on LCD Invalid Password*/
    H_Lcd_WriteString("Invalid Password");
    H_Hc05_SendString("Invalid Password");
    _delay_ms(500);
    WrongEntry++;
  }
  else if ((ValidUsername != 3) && (ValidPassword != 4))
  {
    H_Lcd_WriteString("Invalid Username");
    H_Lcd_GoTo(1, 0);
    H_Lcd_WriteString("Invalid Password");
    _delay_ms(500);
    H_Hc05_SendString("Invalid Username & Password");
    /*Print on LCD Invalid Username & Invalid Password*/
    WrongEntry++;
  }
  else
  {
    /*Do Nothing*/
  }
  _delay_ms(300);
  H_Lcd_Clear();
  _delay_ms(300);
  return WrongEntry;
}

u8 UserLogin (u8* ID, u8* Password)
{
  u8 NumberOfUsers = H_Eeprom_Read(0, 100);
  u8 UserLocation = 0, ValidUsername = 0, ValidPassword = 0, Counter = 0, EEPROMData = 0, WrongEntry = 0, EEPROMDataLocation = 0;
  if (NumberOfUsers > 0)
  {
    for (; Counter < NumberOfUsers; Counter++)
    {
      ValidPassword = 0;
      ValidUsername = 0;
      UserLocation = Counter * 7;
      u8 Check = 0;

      for (; Check < 3; Check++)
      {
        EEPROMDataLocation = UserLocation + Check;
        EEPROMData = H_Eeprom_Read(0, (EEPROMDataLocation));
        if (ID[Check] == EEPROMData)
        {
          ValidUsername++;
        }

      }

      for (Check = 0; Check < 4; Check++)
      {
        EEPROMDataLocation = UserLocation + Check + 3;
        EEPROMData = H_Eeprom_Read(0, (EEPROMDataLocation));
        if (Password[Check] == EEPROMData)
        {
          ValidPassword++;
        }

      }

      if (ValidUsername == 3 && ValidPassword == 4)
      {
        break;
      }
      else
      {
        ValidUsername = 0;
        ValidPassword = 0;
      }
    }
    if (ValidUsername == 3 && ValidPassword == 4)
    {
      /*print on LCD Login Successful*/
      H_Lcd_WriteString("Login Successful");
      H_Hc05_SendString("Login Successful");
    }
    else
    {
      /*print on LCD Invalid Username Or Password*/
      H_Lcd_Clear();
      H_Lcd_WriteString("Invalid Username");
      H_Lcd_GoTo(1, 0);
      H_Lcd_WriteString("Or Password");
      H_Hc05_SendString("Invalid Username Or Password");
      _delay_ms(1000);
      WrongEntry++;

    }
  }
  else
  {
    /*print on LCD There is no users added yet*/
    H_Lcd_Clear();
    H_Lcd_WriteString("There is no users");
    H_Lcd_GoTo(1, 0);
    H_Lcd_WriteString("added yet");
    H_Hc05_SendString("There is no users added yet");
    _delay_ms(1000);
    WrongEntry = 2;
  }
  return WrongEntry;
}

/************************************************************************/
/*Parameters input array to save in it the input from keypad      */
/*for the ID                              */
/************************************************************************/
void InputID (u8* ID, u8 Mode)
{
  u8  DigitsEntered = 0, KeyPressed = 0 , BluetoothData = 0;
  switch (Mode)
  {
    case AdminMode:
      H_Lcd_Clear();
      H_Lcd_GoTo(0, 0);
      H_Lcd_WriteString("Enter User ID");
      H_Lcd_GoTo(1, 0);
      while (DigitsEntered < 3)
      {
        BluetoothData = H_Hc05_Rec();
        if (BluetoothData)
        {
          ID[DigitsEntered] = BluetoothData;
          H_Lcd_WriteCharacter(ID[DigitsEntered]);
          DigitsEntered++;
        }
      }
      _delay_ms(50);
      break;

    case UserMode:
      H_Lcd_GoTo(1, 0);
      while (DigitsEntered < 3)
      {
        KeyPressed = H_KeyPad_Read();
        if (KeyPressed)
        {
          ID[DigitsEntered] = KeyPressed;
          /*Print on LCD Numbers Entered*/
          H_Lcd_WriteCharacter(ID[DigitsEntered]);
          DigitsEntered++;
        }
      }
      _delay_ms(300);
      break;

    default:      break;
  }
}

/************************************************************************/
/*Parameters input array to save in it the input from keypad      */
/*for the password                            */
/************************************************************************/
void InputPassword (u8* Password, u8 Mode)
{
  u8 BluetoothData = 0, DigitsEntered = 0, KeyPressed = 0;
  switch (Mode)
  {
    case AdminMode:
      H_Lcd_Clear();
      H_Lcd_GoTo(0, 0);
      H_Lcd_WriteString("Enter Password");
      H_Lcd_GoTo(1, 0);
      while (DigitsEntered < 4)
      {
        BluetoothData = H_Hc05_Rec();
        if (BluetoothData)
        {
          Password[DigitsEntered] = BluetoothData;
          H_Lcd_WriteCharacter('*');
          DigitsEntered++;
        }
      }
      _delay_ms(50);
      break;

    case UserMode:
      H_Lcd_GoTo(1, 0);
      while (DigitsEntered < 4)
      {
        KeyPressed = H_KeyPad_Read();
        if (KeyPressed)
        {
          Password[DigitsEntered] = KeyPressed;
          /*Print on LCD Stars for every character entered*/
          H_Lcd_WriteCharacter('*');
          DigitsEntered++;
        }
      }
      _delay_ms(300);
  }

}
void SwitchDoor (u8* DoorOpened)
{
  if (*DoorOpened == 0)
  {
    H_Lcd_Clear();
    H_Lcd_GoTo(0, 0);
    H_Lcd_WriteString("Door Is Opened");
    H_Hc05_SendString("Door Is Opened");
    H_Servo_SetAngel(120);
    _delay_ms(500);
    *DoorOpened = 1;
  }
  else
  {
    H_Lcd_Clear();
    H_Lcd_GoTo(0, 0);
    H_Lcd_WriteString("Door Is Closed");
    H_Hc05_SendString("Door Is Opened");
    H_Servo_SetAngel(0);
    _delay_ms(500);
    *DoorOpened = 0;
  }

}

void RelaySwitch(u8* RelayOpened)
{
  if (*RelayOpened == 0)
  {
    H_Lcd_Clear();
    H_Lcd_GoTo(0, 0);
    H_Lcd_WriteString("LAMPS Is ON");
    H_Hc05_SendString("LAMPS Is ON");
    H_Relay_On();
    *RelayOpened = 1;
  }
  else if (*RelayOpened == 1)
  {
    H_Lcd_Clear();
    H_Lcd_GoTo(0, 0);
    H_Lcd_WriteString("LAMPS Is OFF");
    H_Hc05_SendString("LAMPS Is OFF");
    H_Relay_Off();
    *RelayOpened = 0;
  }
}

void ACSwitch (u8* ACOpened)
{
	if (*ACOpened == 0)
	{
	 u8 Temperature = 0;
	 Temperature = H_Lm35_Read();
	 if (Temperature > 26)
	 {
		 H_DcMotor_SetDirection(CW);
		 H_DcMotor_Speed(100);
		 H_DcMotor_Start();
	 }
	 else if (Temperature < 21)
	 {
		 H_DcMotor_Stop();
	 }
	 
	 *ACOpened = 1;
	 
 }
 else
 {
	 H_DcMotor_Stop();
	 H_Led_Off(LED_1);
	 H_Led_Off(LED_0);
	 *ACOpened = 0;
 }
}

void CheckEEPROM (void)
{
  //char NumberOfUsers = 0;
  //NumberOfUsers = H_Eeprom_Read(0,100);
  //H_Lcd_WriteNumber(NumberOfUsers);
  //char counter = NumberOfUsers* 7;
  for (char i = 0; i <= 16; i++)
  {
    H_Lcd_WriteCharacter(H_Eeprom_Read(0, i));
    //_delay_ms(250);
    //  H_Lcd_Clear();
  }
  H_Lcd_GoTo(1, 0);
  for (char i = 17; i < 33; i++)
  {
    H_Lcd_WriteCharacter(H_Eeprom_Read(0, i));
    //_delay_ms(250);
    //  H_Lcd_Clear();
  }
}

void DeleteAll (void)
{
  for (u16 i = 0; i <= 0xFF; i++)
  {
    H_Eeprom_Write(0xFF, 0, i);
  }
  //H_Eeprom_Write(0xFF,0,0xFF);
  H_Eeprom_Write(0, 0, 100);
}

void AppInit(void)
{
  H_Eeprom_Write('1', 0, 101);
  H_Eeprom_Write('2', 0, 102);
  H_Eeprom_Write('3', 0, 103);
  H_Eeprom_Write('1', 0, 104);
  H_Eeprom_Write('2', 0, 105);
  H_Eeprom_Write('3', 0, 106);
  H_Eeprom_Write('4', 0, 107);
}

void WelcomingMsg(void)
{
  H_Lcd_Clear();
  H_Lcd_WriteString("Welcome to Smart");
  H_Lcd_GoTo(1, 0);
  H_Lcd_WriteString("Home Project");
  _delay_ms(2000);
  H_Lcd_Clear();
  H_Hc05_SendString("Welcome to Smart Home Project");
}

void CloseTheDoor(void)
{
  H_Servo_SetAngel(0);
  H_Relay_Off();
}


void CheckAC(u8 ACState)
{
  if (ACState == 1)
  {
	  u8 Temperature = 0;
	  Temperature = H_Lm35_Read();
	  if (Temperature >= 26)
	  {
		  H_DcMotor_SetDirection(CW);
		  H_DcMotor_Speed(100);
		  H_DcMotor_Start();
	  }
	  else if (Temperature < 21)
	  {
		  H_Led_On(LED_1);
		  H_Led_Off(LED_0);
		  H_DcMotor_Stop();
	  }
	  H_Lcd_Clear();
	  H_Lcd_WriteString("AC Opened");
	  H_Hc05_SendString("AC Opened");
  }
  else
  {
	  H_DcMotor_Stop();
	  H_Lcd_Clear();
	  H_Lcd_WriteString("AC Closed");
	  H_Hc05_SendString("AC Closed");
  }
}

void CheckRelay(u8 RelayState)
{
  if (RelayState == 1)
  {
    H_Lcd_WriteString(" Relay On");
    H_Hc05_SendString(" Relay On");
    H_Relay_On();
  }
  else if (RelayState == 0)
  {
    H_Lcd_WriteString(" Relay Off");
    H_Hc05_SendString(" Relay Off");
    H_Relay_Off();
  }
}

void CheckDoor(u8 DoorState)
{
  if (DoorState == 1)
  {
    H_Lcd_GoTo(1, 0);
    H_Lcd_WriteString("Door Is Opened");
    H_Hc05_SendString("Door Is Opened");
    H_Servo_SetAngel(120);
    _delay_ms(500);
  }
  else
  {
    H_Lcd_GoTo(1, 0);
    H_Lcd_WriteString("Door Is Closed");
    H_Hc05_SendString("Door Is Closed");
    H_Servo_SetAngel(0);
    _delay_ms(500);
  }

}

void Reset(u8* ACState, u8* DoorState, u8* RelayState)
{
  *ACState = 0;
  *DoorState = 0;
  *RelayState = 0;
  H_DcMotor_Stop();
  CloseTheDoor();
  H_Relay_Off();
  H_Hc05_SendString("A/C Off");
  H_Hc05_SendString("Door is closed");
  H_Hc05_SendString("Relay Off");
  H_Hc05_SendString("Resetting  the system...");
  DeleteAll();
  AppInit();
}

