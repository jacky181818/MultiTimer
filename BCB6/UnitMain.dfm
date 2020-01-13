object Form1: TForm1
  Left = 202
  Top = 94
  BorderStyle = bsDialog
  Caption = #22810#37325#23450#26102#25552#37266#24037#20855
  ClientHeight = 576
  ClientWidth = 761
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Times New Roman'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 14
  object GroupBox2: TGroupBox
    Left = 305
    Top = 0
    Width = 456
    Height = 576
    Align = alClient
    Caption = #25552#37266#31649#29702
    TabOrder = 0
    object CheckListBox1: TCheckListBox
      Left = 2
      Top = 16
      Width = 452
      Height = 517
      Align = alClient
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ItemHeight = 14
      TabOrder = 0
    end
    object Panel4: TPanel
      Left = 2
      Top = 533
      Width = 452
      Height = 41
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 1
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 305
    Height = 576
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 305
      Height = 576
      Align = alClient
      Caption = #28155#21152#25552#37266
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 24
        Width = 48
        Height = 14
        Caption = #25552#37266#26041#24335
      end
      object Label2: TLabel
        Left = 187
        Top = 512
        Width = 48
        Height = 14
        Caption = #36827#34892#25552#37266
      end
      object Label4: TLabel
        Left = 16
        Top = 108
        Width = 36
        Height = 14
        AutoSize = False
        Caption = #22791#27880#65306
      end
      object Panel2: TPanel
        Left = 72
        Top = 47
        Width = 223
        Height = 52
        BevelOuter = bvNone
        TabOrder = 4
        Visible = False
        object Label5: TLabel
          Left = 6
          Top = 5
          Width = 24
          Height = 14
          Caption = #26085#26399
        end
        object Label6: TLabel
          Left = 6
          Top = 30
          Width = 24
          Height = 14
          Caption = #26102#38388
        end
        object DateTimePicker2: TDateTimePicker
          Left = 42
          Top = 3
          Width = 120
          Height = 22
          CalAlignment = dtaLeft
          Date = 41019.3845210301
          Format = 'yyyy'#24180'MM'#26376'dd'#26085
          Time = 41019.3845210301
          DateFormat = dfLong
          DateMode = dmComboBox
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          Kind = dtkDate
          ParseInput = False
          TabOrder = 0
        end
        object DateTimePicker3: TDateTimePicker
          Left = 42
          Top = 28
          Width = 120
          Height = 22
          CalAlignment = dtaLeft
          Date = 41019.384562419
          Format = 'HH:mm:ss'
          Time = 41019.384562419
          DateFormat = dfShort
          DateMode = dmComboBox
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          Kind = dtkTime
          ParseInput = False
          TabOrder = 1
        end
      end
      object ComboBox1: TComboBox
        Left = 72
        Top = 22
        Width = 225
        Height = 22
        Style = csDropDownList
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ItemHeight = 14
        ItemIndex = 0
        TabOrder = 0
        Text = #20174#29616#22312#24320#22987#36807'XXX'#26102#38388#21518#25552#37266
        OnChange = ComboBox1Change
        Items.Strings = (
          #20174#29616#22312#24320#22987#36807'XXX'#26102#38388#21518#25552#37266
          #21040#25351#23450#30340#26085#26399#26102#38388#24320#22987#25552#37266)
      end
      object CheckBox1: TCheckBox
        Left = 15
        Top = 511
        Width = 105
        Height = 17
        Caption = #22312#35774#23450#26102#38388#25552#21069
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object ComboBox2: TComboBox
        Left = 118
        Top = 509
        Width = 66
        Height = 22
        Style = csDropDownList
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ItemHeight = 14
        ItemIndex = 0
        TabOrder = 2
        Text = '1'#20998#38047
        Items.Strings = (
          '1'#20998#38047
          '2'#20998#38047
          '3'#20998#38047
          '4'#20998#38047
          '5'#20998#38047)
      end
      object Panel1: TPanel
        Left = 72
        Top = 48
        Width = 223
        Height = 52
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 3
        object Label3: TLabel
          Left = 5
          Top = 4
          Width = 212
          Height = 14
          AutoSize = False
          Caption = #25552#37266#26102#38388#36824#26377#65306
        end
        object DateTimePicker1: TDateTimePicker
          Left = 75
          Top = 24
          Width = 81
          Height = 22
          CalAlignment = dtaLeft
          Date = 41019.3794459607
          Format = 'HH:mm:ss'
          Time = 41019.3794459607
          DateFormat = dfShort
          DateMode = dmComboBox
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          Kind = dtkTime
          ParseInput = False
          TabOrder = 0
        end
      end
      object btnAddRecord: TBitBtn
        Left = 234
        Top = 541
        Width = 60
        Height = 25
        Caption = #28155#21152
        TabOrder = 5
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B0000100000000000000000000000007F
          7F007F7F00007F7F7F000000FF0000FFFF00BFBFBF00FFFFFF00000000000000
          0000000000000000000000000000000000000000000000000000666666666666
          6000600000000000067306666666666666000777777777777600600000000000
          0773030550025107000000550700255000440555506005557034005555005550
          0606630555555500707660555555555007064075055505706004440060507007
          7044444070706707044466660707703066666666603070066666}
      end
      object Memo1: TMemo
        Left = 16
        Top = 128
        Width = 281
        Height = 377
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          'Memo1')
        TabOrder = 6
      end
    end
  end
end
