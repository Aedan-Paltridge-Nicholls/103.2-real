// VS2022 103.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Project\Properties\Configuration\Properties\C++ Language Standard /std:c++latest 
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <iostream>
constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_BACKSPACE = 8;

using namespace std;
FILE* stream;

char* Fixer(string InpStr)
{
    string Str17 = InpStr;
    char* Fixer = new char[Str17.length() + 1]; // Creates The char* fixer and makes it one longer than str7.
    strcpy_s(Fixer, Str17.length() + 1, Str17.c_str());// Makes The char* fixer and makes have The same content as str7.

    return Fixer;
}
string Formatter(string input) // Formats strings to replace spaces with underscores
{
    char Sp = 32;                // A space. " "
    char Us = 95;                // An Underscore _
    size_t Inputlength = input.length();
    char* Formatter = new char[input.length() + 1];
    strcpy_s(Formatter, input.length() + 1, input.c_str());
    for (size_t i = 0; i < input.length(); i++)
    {
        if (Formatter[i] == Sp)
        {
            Formatter[i] = Us;
        }
    }
    

    return Formatter;
}
void startup() // Checks if The files for The program exist and if not creates them.
{
   
    system("if not exist C:\\logins\\Teachers mkdir C:\\logins\\Teachers");
    system("tree /F  C:\\logins");
}
void makefile(string content, string directory, string filename) // Make a text file in  a choosen  directory.
{
    string Bs = "\\";  // A Back slash
    char Qm = 34;      // A Quotation mark.
    string command = " echo. ";
    string AA = " >> "; // Two arrows so that, it will add to a file, not overwrite it.
    string out = command + Qm + content + Qm + AA + directory + Bs + filename + ".txt";
    system(Fixer(out));
}
void makefolder(string input, string directory, string warning) // Make folder in  a choosen  directory.
{
    string Ck = "if not exist "; // Checks if a directory exists
    string C1 = " mkdir ";       // Command Makes directory
    string C2 = " else ";        // Command two
    string C3 = " echo. ";       // Command puts warning text in console.
    string Bs = "\\";            // A Back slash
    string Ob = "(";             // A Open bracket.
    string Cb = ")";             // A Closed bracket.
    char Sp = 32;                // A space.
    char Qm = 34;                // A Quotation mark.
    string out = Ck + directory + Bs + input += Sp + Ob + C1 + directory + Bs + input + Cb + C2 + Ob + C3 += Qm + warning += Qm + Cb;
    system(Fixer(out));
}
void AddATeacher() 
{
    cin.ignore();
    string path = "C:\\logins\\Teachers";            // Path to folder;
    string error = "Inputted teacher already exists"; // Warns if The inputted teacher's name already exists;
    string input = "";
    cout << "Name of Teacher  ";
    getline(cin, input);
    input = Formatter(input);
    makefolder(input, path, error);
    system("TREE C:\\logins");
}
string OutTime[14] = { "00:00","00:00","00:00","00:00","00:00","00:00","00:00","00:00","00:00","00:00","00:00","00:00","00:00","00:00" };
void SetTimetable()
{
    for (int i = 0; i < 14; i++)
    {
        OutTime[i] = "00:00";
    }
    
    bool ChangedTime = false;
 
    string Weekdays[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    string StartOrEnd[2] = { "Start","End" };
    int input = 0, Time = 555, x = 5, Runs = 1, sre = 1, days = 0, Index = 0, TimeArray[4] = { 0,0,0,0 };
    int Highlow[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, laststart = 0;// These are for checking if "Time", end time is Higher or lower than the Last start time.
    while (true)
    {
        
        if (Runs >= 2){Index = Runs - 2;}
        string out = "NA";
        input = 0;
        system("cls");
        if (Runs % 2 != 0) { sre = 1; }
        else { sre = 2; }
        if (sre == 2)
        {
            
            laststart = Highlow[(Index)];
            if (Time < laststart) { Time = Time + laststart; }
        }
        

        if (days > 6) { break; } 
        cout << "Press Up arrow key  or Down arrow key to increase or decrease the time." << endl;
        cout << "Press Left arrow key  or Right arrow key to decrease or increase the increment." << endl;
        cout << "Set time to 0000 or don't change the time to skip a day; " << endl;
        if (Time < 10) { cout << "000"; }
        else if (Time < 100 && Time >= 10) { cout << "00"; }
        else if (Time < 1000 && Time >= 100) { cout << "0"; }
        cout << Time << " :" << StartOrEnd[(sre - 1)] << " " << Weekdays[days] << " Time change by :" << x << endl;


        switch ((input = _getch()))
        {
            case KEY_UP:// When the Up arrow is pushed increases Time by x
            {
                for (int t = 0; t < 4; t++)
                {
                    TimeArray[(3 - t)] = Time % 10;
                    Time /= 10;
                }
                {   int UP = 0;
                do
                {
                    TimeArray[3]++;
                    if (TimeArray[3] > 9)
                    {
                        TimeArray[3] = 0;
                        TimeArray[2]++;
                        if (TimeArray[2] > 6)
                        {
                            TimeArray[2] = 0;
                            TimeArray[1]++;
                            if (TimeArray[1] > 9 && TimeArray[0] < 2)
                            {
                                TimeArray[1] = 0;
                                TimeArray[0]++;

                            }
                            else if (TimeArray[1] > 4 && TimeArray[0] == 2)
                            {
                                for (int t = 0; t < 4; t++)
                                {
                                    TimeArray[t] = 0;
                                }
                            }
                            else if (TimeArray[1] > 4 && TimeArray[0] > 2)
                            {
                                for (int t = 0; t < 4; t++)
                                {
                                    TimeArray[t] = 0;
                                }
                            }
                        }
                    }
                    UP++;

                } while (UP != x);
                Time =
                    (TimeArray[0] * 1000) +
                    (TimeArray[1] * 100) +
                    (TimeArray[2] * 10) +
                    (TimeArray[3] * 1);
                    ChangedTime = true;

                }
            }
            break;
            case KEY_DOWN:// When the Down arrow is pushed decreases Time by x
            {
                for (int t = 0; t < 4; t++)
                {
                    TimeArray[(3 - t)] = Time % 10;
                    Time /= 10;
                }
                {   int Down = 0;
                do
                {
                    TimeArray[3]--;
                    if (TimeArray[3] < 0)
                    {
                        TimeArray[3] = 9;
                        TimeArray[2]--;
                        if (TimeArray[2] < 0)
                        {

                            TimeArray[2] = 5;
                            TimeArray[1]--;
                            if (TimeArray[1] < 0)
                            {
                                TimeArray[1] = 9;
                                TimeArray[0]--;
                                if (TimeArray[0] < 0)
                                {
                                    TimeArray[1] = 4;
                                    TimeArray[0] = 2;
                                }
                            }
                        }
                    }
                    Down++;

                } while (Down != x);


                }

                Time =
                    (TimeArray[0] * 1000) +
                    (TimeArray[1] * 100) +
                    (TimeArray[2] * 10) +
                    (TimeArray[3] * 1);
                ChangedTime = true;
            }
            break;
            case KEY_LEFT:// When the Left arrow is pushed decreases x by 15 until 15, then decreases x by 5 only if x above 0
            {
                if (x == 5)
                {
                    x = 5;
                }
                else if (x == 10)
                {
                    x = 5;
                }
                else if (x == 15)
                {
                    x = 10;
                }
                else
                {
                    x = x - 15;
                }
            }
            break;
            case KEY_RIGHT:// When the Right arrow is pushed increases x by 5 until 15, then increases x by 15 only if x Below 60
            {
                if (x < 60)
                {
                    if (x == 0)
                    {
                        x = 5;
                    }
                    else if (x == 5)
                    {
                        x = 10;
                    }
                    else if (x == 10)
                    {
                        x = 15;
                    }
                    else
                    {
                        x = x + 15;
                    }
                }
            }
            break;
            case KEY_ENTER: 
            { 
               
                for (int t = 0; t < 4; t++)
                {
                    TimeArray[(3 - t)] = Time % 10;
                    Time /= 10;
                }
                if (Runs % 2 == 0) { days++; }
                Highlow[Runs - 1] = Time;
                Time =
                (TimeArray[0] * 1000) +
                (TimeArray[1] * 100) +
                (TimeArray[2] * 10) +
                (TimeArray[3] * 1); 
                if (Time == 0 || ChangedTime == false) 
                {
                    
                    OutTime[(Runs - 1)] = "NULL"; 
                    days++; 
                    OutTime[Runs] = "NULL";
                    Runs += 2;
                    sre = 1;
                    Time = 730;
                    break;
                }
                out ="";
                for (int n = 0; n < 4; n++)
                {
                    if (n == 2) { out += ":"; }
                    out += (to_string(TimeArray[n]));
                   
                }
                OutTime[(Runs - 1)] = out;
                 
                Runs++;
                ChangedTime = false;
            }
            break;
            default:
                break;
        }
       
        for (int t = 0; t < 4; t++)
        {
            TimeArray[(3 - t)] = Time % 10;
            Time /= 10;
        }
        if (TimeArray[2] > 6 || TimeArray[2] == 6 && TimeArray[3] > 0)
        {
            TimeArray[1]++;
            if (TimeArray[1] < 10)
            {
                TimeArray[2] = 0;
                TimeArray[3] = 0;
            }
            else if (TimeArray[0] <= 2)
            {
                TimeArray[0]++;
                TimeArray[1] = 0;
                TimeArray[2] = 0;
                TimeArray[3] = 0;
            }
        }
        else if (TimeArray[0] >= 2 && TimeArray[1] >= 4)
        {
            TimeArray[0] = 0;
            TimeArray[1] = 0;
            TimeArray[2] = 0;
            TimeArray[3] = 0;
        }
        else if (TimeArray[0] < 0 || TimeArray[1] < 0 || TimeArray[2] < 0 || TimeArray[3] < 0)
        {
            TimeArray[0] = 0;
            TimeArray[1] = 0;
            TimeArray[2] = 0;
            TimeArray[3] = 0;
        }
        
        Time =
        (TimeArray[0] * 1000) +
        (TimeArray[1] * 100) +
        (TimeArray[2] * 10) +
        (TimeArray[3] * 1);
        

    }

}
struct Draw
{
    unsigned  char SPc = 32;  // " " Space char
    string SP;
    unsigned  char AAc = 175; // » Two arrows char
    string AA; 
    unsigned  char BKc = 219; // █ Block char
    string BK;
    unsigned  char TLc = 201; // ╔ Top Left char
    string TL; 
    unsigned  char TMc = 203; // ╦ Top Middle char
    string TM;
    unsigned  char TRc = 187; // ╗ Top Right char
    string TR;
    unsigned  char LMc = 205; // ═ Line Middle char
    string LM;
    unsigned  char MMc = 186; // ║ Middle Middle char
    string MM;
    unsigned  char LLc = 204; // ╠ Line Left char
    string LL;
    unsigned  char LCc = 206; // ╬ Line Center char
    string LC; 
    unsigned  char LRc = 185; // ╣ Line Right char
    string LR; 
    unsigned  char BLc = 200; // ╚ Bottom Left char
    string BL;
    unsigned  char BMc = 202; // ╩ Bottom Middle char
    string BM; 
    unsigned  char BRc = 188; // ╝ Bottom Right char
    string BR;
}d;
struct Drawing
{   string NL = " & echo. & echo ";//! "& echo. & echo"
    string NLF = "|";              //New line in the file 
    string Tb = "^|  ^|";          // Adds a tab
    string SP = (d.SP += d.SPc);   //! " " Space
    string AA = (d.AA += d.AAc);   //! » Two arrows 
    string BK = (d.BK += d.BKc);   //! █ Block
    string TL = (d.TL += d.TLc);   //! ╔ Top Left 
    string TM = (d.TM += d.TMc);   //! ╦ Top Middle 
    string TR = (d.TR += d.TRc);   //! ╗ Top Right 
    string LM = (d.LM += d.LMc);   //! ═ Line Middle 
    string MM = (d.MM += d.MMc);   //! ║ Middle Middle 
    string LL = (d.LL += d.LLc);   //! ╠ Line Left 
    string LC = (d.LC += d.LCc);   //! ╬ Line Center 
    string LR = (d.LR += d.LRc);   //! ╣ Line Right 
    string BL = (d.BL += d.BLc);   //! ╚ Bottom Left 
    string BM = (d.BM += d.BMc);   //! ╩ Bottom Middle 
    string BR = (d.BR += d.BRc);   //! ╝ Bottom Right
}D;
string outclasspath;
void convert(string in)

{
        std::u8string  output;
        output = u8"";
    char* working = new char[in.length() + 1];
    for (int i = 0; i < in.length(); i++)
    { 
        working[i] = in[i];
    } 
    working[in.size()] = '\0';
    for (int i = 0; i < in.length(); i++)
    {
   
        switch (working[i])
        {
          case 'É'://! ╔ Top Left 
          {
              output += u8"╔";
          }
          break;
          case 'Í'://! ═ Line Middle 
          {
              output += u8"═";
          }
          break;
          case 'Ë'://! ╦ Top Middle 
          {
              output += u8"╦";
          }
          break;
          case '»'://! ╗ Top Right 
          {
              output += u8"╗";
          }
          break;
          case 'º'://! ║ Middle Middle
          {
              output += u8"║";
          }
          break;
          case 'Ì'://! ╠ Line Left 
          {
              output += u8"╠";
          }
          break;
          case 'Î'://! ╬ Line Center 
          {
              output += u8"╬";
          }
          break;
          case '¹'://! ╣ Line Right 
          {
              output += u8"╣";
          }
          break;
          case 'Û'://! █ Block
          {
              output += u8"█";
          }
          break;
          case 'È'://! ╚ Bottom Left 
          {
              output += u8"╚";
          }break;
          case 'Ê'://! ╩ Bottom Middle 
          {
              output += u8"╩";
          }
          break;
          case '¼': //! ╝ Bottom Right
          {
              output += u8"╝";
          }
          break;
          case '¯': //! » Two arrows
          {
              output += u8"»";
          }
          break;
          case ' '://! " " Space
          {
              output += u8" ";
          }
          break;
          case '|'://! New line in the file
          {
              output += u8"\n";
          }
          break;
          case '*'://! * Asterisk this is for ending the info file
          {
              output  = u8" Students in this class : ";
          }
          break;
          default:
          {
              output += working[i];
          }
          break;
        }
    }
        u8string u8str = output;
    //    u8str += u8"\n";
        ofstream out(outclasspath, ios_base::app);
        out << string_view(reinterpret_cast<const char*>(u8str.data()), u8str.size());
        out.close();
    delete[] working;
}
string timetableout[17] = { "","","","","","","","","","","","","","","","",""};

void Timetable()
{
    
    
    unsigned  char BKc = 219;
    int left = 11;           // Size of the left half
    int right = 15;          // Size of the right half
    //string Block =""; Block += BKc;
    string Hours = "Hours";
    string Days = "Days";
    string Weekdays[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    string InTimes[7] = { "","","","","","","" };
    string Times[7] = { "","","","","","","" };
   // cout << Block;
    string Blocks[15] = { D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK,D.BK, };
    SetTimetable();
    system("cls");
    int StartClass = 0;
    int EndClass = 1;

    for (int R = 0; R < 7; R++) 
    {
        if (OutTime[StartClass] == "NULL" && OutTime[EndClass] == "NULL")
        {
            for (int b = 0; b < 15; b++) { Times[R] += Blocks[b]; }
            StartClass = StartClass + 2;
            EndClass = EndClass + 2;
            continue;
        }
        Times[R] = (OutTime[StartClass].append(D.SP), OutTime[StartClass].append(D.AA), OutTime[StartClass].append(D.SP)); //TEST THIS
        Times[R].append(OutTime[EndClass]);
        StartClass = StartClass + 2;
        EndClass = EndClass + 2;
    }
 
    string Top = "";
    string Header = "";
    string Divider = "";
    string Content[7];
    string Bottom = "";
    Top.append(D.TL); // The Top of the timetable
    {
        for (int i = 0; i < left; i++)
        {
            Top.append(D.LM);
        }
        Top.append(D.TM);
        for (int i = 0; i < right; i++)
        {
            Top.append(D.LM);
        }
        Top.append(D.TR);
    }
    Header.append(D.MM); // The header of the timetable
    {
        size_t h, d;
        d = ((left - Days.length()) / 2) ;
        h = ((right - Hours.length()) / 2) ;
        Days.append(D.SP);
        for (size_t i = 0; i < d; i++) { Header.append(D.SP); }
        Header.append(Days);
        for (size_t i = 0; i < d; i++) { Header.append(D.SP); }
        Header.append(D.MM);
        for (size_t i = 0; i < h; i++) { Header.append(D.SP); }
        Header.append(Hours);
        for (size_t i = 0; i < h; i++) { Header.append(D.SP); }


        Header.append(D.MM);
    }
    Divider.append(D.LL);// The divider between each of day of the timetable
    {
        for (int i = 0; i < left; i++)
        {
            Divider.append(D.LM);
        }
        Divider.append(D.LC);
        for (int i = 0; i < right; i++)
        {
            Divider.append(D.LM);
        }
        Divider.append(D.LR);
    }
    Bottom.append(D.BL); // The bottom of the timetable
    {
        for (int i = 0; i < left; i++)
        {
            Bottom.append(D.LM);
        }
        Bottom.append(D.BM);
        for (int i = 0; i < right; i++)
        {
            Bottom.append(D.LM);
        }

        Bottom.append(D.BR);
    }
    // The content of the timetable
    {
        for (int i = 0; i < 7; i++)
        {
            size_t v = ((left)-(Weekdays[i].length())-1 );
            Content[i].append(D.MM);
            Content[i].append(D.SP);
            Content[i].append(Weekdays[i]);
            for (size_t j = 0; j < v; j++)
            {
                Content[i].append(D.SP);
            }
            if (Times[i].find(D.BK) != string::npos )
            {
                Content[i].append(D.MM);
                Content[i].append(Times[i]);
                Content[i].append(D.MM);
            }
            else
            {
                Content[i].append(D.MM);
                Content[i].append(D.SP);
                Content[i].append(Times[i]);
                Content[i].append(D.SP);
                Content[i].append(D.MM);
            }
        }
    }
    
   

        cout << Top << endl;
        cout << Header << endl;
         for (int i = 0; i < 7; i++)
         {
             cout << Divider << endl;
             cout << Content[i] << endl;     
         }
         cout << Bottom << endl;
   
        int day = 0;

      
        string path = "C:\\logins\\Teachers";
    convert(Top);
    convert(Header);
    for (int i = 3; i < 17; i += 2)
    { 
        int loops = i;
        convert(Divider);
        convert(Content[day]);
        day++;
    }
    convert(Bottom);

    string endinfofile = "|*";
    endinfofile.append(D.NLF);// Top of student table 
    {
        endinfofile.append(D.TL);
        for (int i = 0; i < 40; i++) { endinfofile.append(D.LM); }
        endinfofile.append(D.TM);
        for (int i = 0; i < 9; i++) { endinfofile.append(D.LM); }
        endinfofile.append(D.TM);
        for (int i = 0; i < 16; i++) { endinfofile.append(D.LM); }
        endinfofile.append(D.TR);

    }
    endinfofile.append(D.NLF);// Headers of student table 
    {
        endinfofile.append(D.MM);
        string  H1 = "Students's Full Name";          //Header One.
        for (int i = 0; i < 10; i++) { endinfofile.append(D.SP); }
        endinfofile.append(H1);
        for (int i = 0; i < 10; i++) { endinfofile.append(D.SP); }
        endinfofile.append(D.MM);
        string H2 = "Gender";                        //Header two.
        endinfofile.append(D.SP);
        endinfofile.append(H2);
        for (int i = 0; i < 2; i++) { endinfofile.append(D.SP); }
        endinfofile.append(D.MM);
        string  H3 = "Date of Birth ";               //Header three.
        endinfofile.append(D.SP);
        endinfofile.append(H3);
        endinfofile.append(D.SP);
        endinfofile.append(D.MM);
    }
    endinfofile.append(D.NLF);// Divider of Student table.
    {
        endinfofile.append(D.LL);
        for (int i = 0; i < 40; i++) { endinfofile.append(D.LM); }
        endinfofile.append(D.LC);
        for (int i = 0; i < 9; i++) { endinfofile.append(D.LM); }
        endinfofile.append(D.LC);
        for (int i = 0; i < 16; i++) { endinfofile.append(D.LM); }
        endinfofile.append(D.LR);
    }
    endinfofile.append(D.NLF);// End of endinfofile. 
    convert(endinfofile);
}


    /*
    * TeacherName = str1   //The teacher's name
    *  ClassName = str2     // The name of the class
    *  ClassType = str3     // The class's Type ie Maths, English, History, ect.
    *  startdate = str4     // The new class's  start date
    *  Enddate = str5       // The new class's  end date
    *  path = str6  
    * Name of the teacher : "TeacherName" |  | Start date : "start" |  | End date : "end"
    * Name of "TeacherName"'s class : "ClassName" |  |  "ClassName"'s class Type : "ClassType"
    * TeacherName"'s "ClassName"'s Time table :
    */
    /*╔═══════════╦═══════════════╗   //  Class time slots to be displayed like : ↓
    * ║   Days    ║     Hours     ║   //            start ↓   ↓ end       not on this day ↓
    * ╠═══════════╬═══════════════╣   //╠═══════════╬═══════════════╣  ╠═══════════╬═══════════════╣
    * ║ Sunday    ║               ║   //║ Sunday    ║ 07:00 » 12:00 ║  ║ Sunday    ║███████████████║
    * ╠═══════════╬═══════════════╣   //╠═══════════╬═══════════════╣  ╠═══════════╬═══════════════╣
    * ║ Monday    ║               ║
    * ╠═══════════╬═══════════════╣
    * ║ Tuesday   ║               ║
    * ╠═══════════╬═══════════════╣
    * ║ Wednesday ║               ║
    * ╠═══════════╬═══════════════╣
    * ║ Thursday  ║               ║
    * ╠═══════════╬═══════════════╣
    * ║ Friday    ║               ║
    * ╠═══════════╬═══════════════╣
    * ║ Saturday  ║               ║
    * ╚═══════════╩═══════════════╝
    *
    */
void ClassInfoFile(string str1, string str2, string str3, string str4, string str5, string str6 )
{   
    string Bs = "\\";// A Back slash
    string Path = str6 + Bs + Formatter(str1) + Bs + "Classes" + Bs + Formatter(str2);// The path to The file                                                  
    outclasspath = Path + Bs + Formatter(str2) + "-info.txt";                             //  and its name.
    string NL = " & echo. & echo: ";                                                   // "& echo. & echo"
    string Sp = " ";                                                                  // A space.
    string Tb = " ^|  ^| ";                                              // Adds a tab
    string SC = "(echo.";                                                // Starts The command
    string EC = ") > ";                                                  // Ends The command
    string L1;                                                           // line one
    string L2;                                                           // line two
    string L3;                                                           // line three
    string T1 = "  Teacher's Name : ";                                   // TeacherName
    string T2 = " Start date : ";                                        // Start date
    string T3 = " End date  : ";                                         // End date
    string T4 = "'s class Type : ";                                       // class Type
    string T5 = "'s class :  ";                                          // Formatting 
    string T6 = " Name of ";                                               // Name of
    string T7 = " :";                                                    // Formatting :
    string T8 = "'s Time table :";                                       // Time table
    string T9 = "'s ";                                                  // Formatting 's
    string FF = ".txt";                                                  // File format
    L1 = T1 + str1 + Tb + T2 + str4 + Tb + T3 + str5 + NL;
    L2 = T6 + str1 + T5 + str2 + Tb + str2 + T4 + str3 + NL;
    L3 = Sp + str1 + T9 + str2 + T8 + NL;
 
    string command = SC + L1 + L2 + L3 + EC + outclasspath;
    system(Fixer(command));
    command = "";
}
void AddAClass() 
{
   
    cin.ignore();
    string Bs = "\\";                            // A Back slash
    string TeacherName;                      // The teacher's name
    string ClassName;                        // The new class's name
    string ClassType;                        // The new class's Type ie Maths, English, History, ect.
    string startdate;                        // The new class's  start date
    string Enddate;                          // The new class's  end date
    string Warning = "Class already exists"; // Warns if The inputted class already exists;
    cout << "The classes teachers name : ";
    getline(cin, TeacherName);
    TeacherName = Formatter(TeacherName);
    cout << "The classes  name :  ";
    getline(cin, ClassName);
    ClassName = Formatter(ClassName);
    cout << "The classes  type : ";
    getline(cin, ClassType);
    cout << "The class's  start date  \n please type in DD-MM-YY Format : "; // The Date of birth of The student.
    getline(cin, startdate);
    cout << "The class's  end date  \n please type in DD-MM-YY Format : "; // The Date of birth of The student.
    getline(cin, Enddate);
    
    ClassType = Formatter(ClassType);
    // ↑Inputs ↓File and folder making
    string path = "C:\\logins\\Teachers";
    makefolder(ClassName, (path += (Bs + Formatter(TeacherName)+ Bs +"Classes")), Warning);
    path = "C:\\logins\\Teachers";// Makes The folder
    ClassInfoFile(TeacherName, ClassName, ClassType, startdate, Enddate, path);
    Timetable();         // Makes The file
}
char Gen;// The students Gender.
string gender()
{

    string out = " ";
    switch (Gen)
    {
        case 'M':
        {
            out.append("Male");
        }
        break;
        case 'F':
        {
         out.append("Female");  
        }
        break;
        case 'O':
        {
            out.append("other");
        }
        break;
        default:
        {
            out.append("?????");
        }
        break;
    }
    Gen = ' ';
    return out;
}
/* This ↓ is the format that will be written to the file.

 * string StudentName      =   str1                       // The name of The student
 * string StudentDOB       =   str2                       // The Date of birth of The student 
 * string gen              =   str3                       // the student's gender.
 * string TeacherName      =   str4;                      // The student's teacher's name.
 * string ClassName        =   str5;                      // The name of The student's class.
 * string path C:\\logins\\teachers\\"TeacherName"\\Classes\\"ClassName"\\"ClassName"-info.txt
 * ie:
 *   40-7-16 
 * ╔════════════════════════════════════════╦════════╦════════════════╗
 * ║          Students's Full Name          ║ Gender ║ Date of Birth  ║     
 * ╠════════════════════════════════════════╬════════╬════════════════╣
 * ║ Aedan Henare Paltridge Nicholls        ║ Male   ║    17-01-04    ║
 * ╠════════════════════════════════════════╬════════╬════════════════╣
 * 
 * 
 */
void SudentInfoToClass(string str1, string str2, string str3, string str4, string str5)
{
    string StudentName = str1;                                                // The name of The student
    string StudentDOB = str2;                                                 // The Date of birth of The student 
    string gen = str3;                                                        // the student's gender.
    string TeacherName = str4;                                                // The student's teacher's name.
    string ClassName = str5;                                                  // The name of The student's class.
    string path = "C:\\logins\\teachers";                                     // Path to the file.
    path += Formatter("\\" + TeacherName + "\\" + "Classes" + "\\");          // Continued.
    path += Formatter(ClassName + "\\" + ClassName + "-info.txt");            // Continued.
    outclasspath = path;                                                      // Finished.
    string ClassStudentInfo = "";
   

    ClassStudentInfo.append(D.NLF);// Column of student table 
    {
        ClassStudentInfo.append(D.MM);
        string  ColumnOne = StudentName;               //Column One.
        ColumnOne.append(D.SP);
        ClassStudentInfo.append(ColumnOne);
        for (size_t i = 0; i < (40 - ColumnOne.size()); i++) { ClassStudentInfo.append(D.SP); }
        //ClassStudentInfo.append(D.SP);
        ClassStudentInfo.append(D.MM);
        
        string ColumnTwo = gen;                        //Column two.
        ColumnTwo.append(D.SP);
        ClassStudentInfo.append(ColumnTwo);
        for (size_t i = 0; i < (9 - ColumnTwo.size()); i++) { ClassStudentInfo.append(D.SP); }
        ClassStudentInfo.append(D.MM);
       
        string  ColumnThree = StudentDOB;             //Column three
        for (int i = 0; i < 4; i++) {  ClassStudentInfo.append(D.SP); }
        ClassStudentInfo.append(ColumnThree);
        for (int i = 0; i < 4; i++) {  ClassStudentInfo.append(D.SP); }
        ClassStudentInfo.append(D.MM);
    }
    ClassStudentInfo.append(D.NLF);// Divider of Student table.
    {
        ClassStudentInfo.append(D.LL);
        for (int i = 0; i < 40; i++) { ClassStudentInfo.append(D.LM); }
        ClassStudentInfo.append(D.LC);
        for (int i = 0; i <  9; i++) { ClassStudentInfo.append(D.LM); }
        ClassStudentInfo.append(D.LC);
        for (int i = 0; i < 16; i++) { ClassStudentInfo.append(D.LM); }
        ClassStudentInfo.append(D.LR);
    }
    ClassStudentInfo.append(D.NLF);// End of ClassStudentInfo. 
    convert(ClassStudentInfo);









}
/*This ↓ is the format that will be written to the file.
 *string StudentName      =   str1                 // The name of The student
 *string StudentDOB       =   str2                 // The Date of birth of The student
 *string Studentparents   =   str3                 // The parents of The student
 *string phonenumber;     =   str4                 // The student's parent's phone number.
 *string Studentaddress;  =   str5                 // The address of The student
 *string Yearlevel;       =   str6                 // The Year level of The student
 *string Path             =   str7                 // The path to The file
 * string TeacherName     =   str8;                // The student's teacher's name.
 * string ClassName       =   str9;                // The name of The student's class.
 *string gender           =   gender()             // the student's gender.
 *format
 *Name "StudentName"  Age "StudentAge"   Year level "Yearlevel"
 *Gender" " Home Address "Studentaddress"
 *Name of parents "Studentparents"  
 * parents phonenumber "phonenumber"
 */
void StudentInfoFile(string str1, string str2, string str3, string str4, string str5, string str6, string str7, string str8, string str9)
{

    char Bs = 92;                                        // A Back slash
    unsigned  char Ob = 40;                              // A Open bracket.
    unsigned  char Cb = 41;                              // A Closed bracket.
    unsigned  char Qm = 34;                              // A Quotation mark.
    string Sp = " ";                                     // A space.
    string gen =  gender();          // the student's gender.
   
    string Path = Formatter(str7) + Bs + Formatter(str1);// The path to The file
    string FN = Formatter(str1);                         // The Name of The file
    string Tb = " ^|  ^| ";                              // Adds a tab
    string SC = "(echo.";                                // Starts The command
    string EC = ") >";                                   // Ends The command
    string NL = "& echo. & echo";                        // adds a new line to a file 
    string SG = ("'s Gender is : " + gen);          // the student's gender.
    string L1;                                           // line one
    string L2;                                           // line two
    string L3;                                           // line three
    string L4;                                           // line three
    string T1 = "Name:";                                 // Name
    string T2 = "'s Date of birth:";                     // Dob
    string T3 = "'s Year level:";                        // Year level
    string T4 = "Home address of";                       // Home address
    string T5 = " :";                                    // Formatting :
    string T6 = "Name of";                               // Name of
    string T7 = "'s : ";                                 // Formatting 's
    string T8 = "'s Parent/s's Phonenumbers:";           // Parent/s's Phonenumbers
    string T9 = ".txt";                                  // File format

    L1 = T1 + Sp + str1 + Sp + Tb + Sp + str1 + T2 + Sp + str2 + Sp + Tb + Sp + str1 + T3 + Sp + str6;
    L2 = Sp + str1 + SG + Sp +Tb+ T4 + Sp + str1 + T5 + Sp + str5;
    L3 = Sp + T6 + Sp + str1 + T7 + Sp + str3 + Sp;
    L4 = Sp + str1 + T8 + Sp + str4;
    string command = SC + Sp + L1 + Sp + NL + Sp + L2 + Sp + NL + Sp + L3 + Sp + NL + Sp + L4 + Sp + EC + Sp + Path + Bs + FN + T9;
    system(Fixer(command));
  //  command = "type " + Path + Bs + FN + T9;
  ///  system(Fixer(command));
    SudentInfoToClass(str1, str2,gen,str8,str9);
}

void AddStudent()
{
 
    cin.ignore();
    string Tb = " ^|  ^| ";                       // Adds a tab
    string path = "C:\\logins\\Teachers";         // The main path.    
    string Bs = "\\";                             // A Back slash.
    string TeacherName = "";                      // The student's teacher's name.
    string ClassName = "";                        // The name of The student's class.
    string StudentName = "";                      // The name of The student.
    string StudentDOB = "";                       // The Date of birth of The student.
    string StudentParents = "";                   // The parents of The student.
    string StudentMother = "";                    // The parents of The student.
    string StudentFather = "";                    // The parents of The student.
    string Phonenumber = "";                      // The student's parent's phone number.
    string MotherPhonenumber = "";                // The student's parent's phone number.
    string FatherPhonenumber = "";                // The student's parent's phone number.
    string Studentaddress = "";                   // The address of The student.
    string Yearlevel = "";                        // The Year level of The student.
    string Warning = "Student already exists";    // Warns if The inputted class already exists.
    // Other info.↓
    cout << "The student's teacher's name  "; // The students teacher's name.
    getline(cin, TeacherName);
    TeacherName = Formatter(TeacherName);
    cout << "The student's class's  name  "; // The name of The student's class.
    getline(cin, ClassName);
    ClassName = Formatter(ClassName);
    // The  Student's info. ↓
    cout << "The student's  name  "; // The name of The student.
    getline(cin, StudentName);
    cout << "The student's  Dob  \n please type in DD-MM-YY Format\n"; // The Date of birth of The student.
    getline(cin, StudentDOB);
    cout << "The student's  parent/parents's names \n" // The parents's names of The student.
        << "If The parents info is unknown or is not applicable type: NA\n";
    cout << "The student's  father's name :";
    getline(cin, StudentFather);
    cout << "The student's  Mother's name :";
    getline(cin, StudentMother);
    cout << "The student's parent/parents's phonenumber  \n" // The student's parents's phonenumbers.
        << "If The parents info is unknown or is not applicable type: NA\n";
    cout << "The student's  father's phonenumber :";
    getline(cin, FatherPhonenumber);
    cout << "The student's  Mother's phonenumber :";
    getline(cin, MotherPhonenumber);
    cout << "The student's  address  "; // The address of The student
    getline(cin, Studentaddress);
    cout << "The student's  Year level  "; // The Year level of The student
    getline(cin, Yearlevel);
    cout << "The student's  Gender\n" // The name of The student.
        << "Male  [M]\nFemale  [F]\nother  [O]\n: ";
    cin >> Gen;
    Gen = toupper(Gen);
    if (StudentFather != "NA") { StudentParents = StudentParents + "Father's name : " + StudentFather.append(Tb); }
    if (StudentMother != "NA") { StudentParents = StudentParents + "Mother's name : " + StudentMother; }
    if (StudentFather == "NA" && StudentMother == "NA") { StudentParents = " Unknown "; }
    if (FatherPhonenumber != "NA") { Phonenumber = Phonenumber + "Father's phonenumber : " + FatherPhonenumber.append(Tb);}
    if (MotherPhonenumber != "NA") { Phonenumber = Phonenumber + "Mother's phonenumber : " + MotherPhonenumber; }
    if (FatherPhonenumber == "NA" && MotherPhonenumber == "NA") { StudentParents = " Unknown "; }
   
    // ↑Inputs ↓ File and folder making

    string Fullpath = path + Bs + TeacherName + Bs + "Classes" + Bs + ClassName; // Path to folder;
    makefolder(Formatter(StudentName), Formatter(Fullpath), Warning);
    StudentInfoFile(StudentName, StudentDOB, StudentParents, Phonenumber, Studentaddress, Yearlevel, Fullpath, TeacherName, ClassName);
}

void Makelogin()// For admins to add Login
{
    string password, username;
    cout << "The student's teacher's name  "; // The students teacher's name.
    getline(cin, username);
    username = Formatter(username);
    cout << "The student's class's  name  "; // The name of The student's class.
    getline(cin, password);
    password = Formatter(password);
}
void login()
{
    string password, username;
    cout << "The student's teacher's name  "; // The students teacher's name.
    getline(cin, username);
    username = Formatter(username);
    cout << "The student's class's  name  "; // The name of The student's class.
    getline(cin, password);
    password = Formatter(password);
}
void interface()

{
    cout << "What do you want to do\nAdd A Class\t[C]\nAdd a Student\t[S]\nAdd a teacher\t[T]\nExit\t\t[E]\n";
    
    cin >> input;
    switch (toupper(input))
    {
    case 'C':
    { AddAClass();
    }
    break;

    case 'S':
    { AddStudent();
    }
    break;
    case 'T':
    {  AddATeacher();
    }
    break;
    case 'E':
    {  system("exit");
    }
    break;
    default:
    {
        cout << "Invalid input try again" << endl;
    }
    break;
    }
}
int main()
{
    //AddStudent();
   // Timetable();

    startup();
    while (true)
    {
        //cin.ignore();
        interface();
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
