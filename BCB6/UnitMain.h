//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <CheckLst.hpp>
#include <vector>

#include "sqlite3.h"
using namespace std;

struct _ST_TIMETIP_{
    TDateTime datetime;
    bool ahead;
    int aheadminutes;
};


typedef struct _ST_TIMETIP_ TIMETIP;
vector<TIMETIP> vtTimerList;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox2;
    TCheckListBox *CheckListBox1;
    TPanel *Panel3;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label4;
    TPanel *Panel2;
    TLabel *Label5;
    TLabel *Label6;
    TDateTimePicker *DateTimePicker2;
    TDateTimePicker *DateTimePicker3;
    TComboBox *ComboBox1;
    TCheckBox *CheckBox1;
    TComboBox *ComboBox2;
    TPanel *Panel1;
    TLabel *Label3;
    TDateTimePicker *DateTimePicker1;
    TBitBtn *btnAddRecord;
    TMemo *Memo1;
    TPanel *Panel4;
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:
    bool __fastcall StartRun(void);
    void __fastcall StopRun(void);
    HANDLE FThread;
    HANDLE hQuitEvent;
    sqlite3 *pDB;	// User declarations
    BOOL bQuitFlag;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    void __fastcall ThreadFun(void);
    bool __fastcall OpenDB(void);
    bool __fastcall CloseDB(void);
    bool __fastcall AddTimerMode1(TDateTime dt, int aheadofSchedule, AnsiString comment);
    bool __fastcall AddTimerMode2(TDateTime dtDate, TDateTime dtTime, int aheadofSchedule, AnsiString comment);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
