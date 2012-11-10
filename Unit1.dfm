object Form1: TForm1
  Left = 363
  Top = 93
  Width = 727
  Height = 666
  Caption = 'Polar Aligner, 2 star'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefaultPosOnly
  ShowHint = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label20: TLabel
    Left = 41
    Top = 192
    Width = 81
    Height = 16
    Caption = 'Point to Star 1'
  end
  object Label21: TLabel
    Left = 41
    Top = 249
    Width = 81
    Height = 16
    Caption = 'Point to Star 2'
  end
  object Label24: TLabel
    Left = 160
    Top = 281
    Width = 74
    Height = 16
    Hint = 'positive error: pointed above the pole'
    Caption = 'elevation err'
  end
  object Label25: TLabel
    Left = 160
    Top = 249
    Width = 76
    Height = 16
    Hint = 'positive err: pointed east of pole'
    Caption = 'azimuth error'
  end
  object Label27: TLabel
    Left = 441
    Top = 233
    Width = 58
    Height = 16
    Caption = 'delta time'
    Visible = False
  end
  object Label28: TLabel
    Left = 441
    Top = 265
    Width = 70
    Height = 16
    Caption = 'determinant'
  end
  object Label29: TLabel
    Left = 441
    Top = 320
    Width = 54
    Height = 16
    Caption = 'Dec ratio'
    Visible = False
  end
  object Label30: TLabel
    Left = 441
    Top = 297
    Width = 48
    Height = 16
    Caption = 'RA ratio'
    Visible = False
  end
  object Label6: TLabel
    Left = 296
    Top = 313
    Width = 41
    Height = 16
    Caption = 'Label6'
    Visible = False
  end
  object Label10: TLabel
    Left = 297
    Top = 336
    Width = 48
    Height = 16
    Caption = 'Label10'
    Visible = False
  end
  object Label7: TLabel
    Left = 608
    Top = 8
    Width = 70
    Height = 16
    Caption = 'Version 003'
  end
  object Star1Grp: TGroupBox
    Left = 25
    Top = 3
    Width = 200
    Height = 134
    Caption = 'Star 1'
    TabOrder = 0
    OnExit = Star1GrpExit
    object Label1: TLabel
      Left = 16
      Top = 94
      Width = 25
      Height = 16
      Anchors = [akLeft, akBottom]
      Caption = 'Dec'
    end
    object Label2: TLabel
      Left = 16
      Top = 61
      Width = 19
      Height = 16
      Anchors = [akLeft, akBottom]
      Caption = 'RA'
    end
    object Label8: TLabel
      Left = 64
      Top = 110
      Width = 24
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'deg'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 73
      Top = 37
      Width = 13
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'hr'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 112
      Top = 37
      Width = 24
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'min'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 160
      Top = 37
      Width = 24
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'sec'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Star1Name: TLabel
      Left = 64
      Top = 20
      Width = 73
      Height = 16
      Caption = '                  '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object S1DD: TEdit
      Left = 57
      Top = 85
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S1DM: TEdit
      Left = 105
      Top = 85
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S1DS: TEdit
      Left = 153
      Top = 85
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S1RH: TEdit
      Left = 57
      Top = 53
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S1RM: TEdit
      Left = 105
      Top = 53
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S1RS: TEdit
      Left = 153
      Top = 53
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object Star1Num: TEdit
      Left = 8
      Top = 16
      Width = 41
      Height = 24
      Hint = 'Enter Meade star number'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnExit = Star1NumExit
      OnKeyPress = NumericOnKeyPress
    end
  end
  object Star2Grp: TGroupBox
    Left = 249
    Top = 3
    Width = 200
    Height = 134
    Caption = 'Star 2'
    TabOrder = 1
    OnExit = Star2GrpExit
    object Label3: TLabel
      Left = 16
      Top = 97
      Width = 25
      Height = 16
      Anchors = [akLeft, akBottom]
      Caption = 'Dec'
    end
    object Label4: TLabel
      Left = 16
      Top = 64
      Width = 19
      Height = 16
      Anchors = [akLeft, akBottom]
      Caption = 'RA'
    end
    object Label9: TLabel
      Left = 64
      Top = 113
      Width = 24
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'deg'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 73
      Top = 40
      Width = 13
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'hr'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label16: TLabel
      Left = 160
      Top = 40
      Width = 24
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'sec'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 112
      Top = 40
      Width = 24
      Height = 17
      Anchors = [akLeft, akBottom]
      Caption = 'min'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Star2Name: TLabel
      Left = 64
      Top = 20
      Width = 73
      Height = 16
      Caption = '                  '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object S2DD: TEdit
      Left = 57
      Top = 88
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S2DM: TEdit
      Left = 105
      Top = 88
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S2DS: TEdit
      Left = 153
      Top = 88
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S2RH: TEdit
      Left = 57
      Top = 56
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S2RM: TEdit
      Left = 105
      Top = 56
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object S2RS: TEdit
      Left = 153
      Top = 56
      Width = 40
      Height = 24
      Anchors = [akLeft, akBottom]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object Star2Num: TEdit
      Left = 8
      Top = 16
      Width = 41
      Height = 24
      Hint = 'Enter Meade star number'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      Text = '0'
      OnExit = Star2NumExit
      OnKeyPress = NumericOnKeyPress
    end
  end
  object LocationGrp: TGroupBox
    Left = 473
    Top = 59
    Width = 200
    Height = 79
    Caption = 'Location'
    TabOrder = 2
    OnExit = LocationGrpExit
    object Label5: TLabel
      Left = 16
      Top = 41
      Width = 18
      Height = 16
      Caption = 'Lat'
    end
    object Label13: TLabel
      Left = 64
      Top = 16
      Width = 24
      Height = 17
      Caption = 'deg'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label17: TLabel
      Left = 160
      Top = 16
      Width = 24
      Height = 17
      Caption = 'sec'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 112
      Top = 16
      Width = 24
      Height = 17
      Caption = 'min'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object LatD: TEdit
      Left = 57
      Top = 32
      Width = 40
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object LatM: TEdit
      Left = 105
      Top = 32
      Width = 40
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object LatS: TEdit
      Left = 153
      Top = 32
      Width = 40
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
  end
  object Button1: TButton
    Left = 32
    Top = 160
    Width = 97
    Height = 25
    Hint = 'Slews to Star 1'
    Caption = 'Goto Star 1'
    Enabled = False
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 217
    Width = 97
    Height = 24
    Hint = 'Syncs to Star1, Slews to Star 2'
    Caption = 'Goto Star 2'
    Enabled = False
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 32
    Top = 272
    Width = 97
    Height = 25
    Hint = 'Finds Star 2 RA and Dec error and computes mount errors'
    Caption = 'Compute error'
    TabOrder = 7
    OnClick = Button3Click
  end
  object errED: TEdit
    Left = 249
    Top = 272
    Width = 40
    Height = 24
    Hint = 'positive error: pointed above the pole'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 8
    Text = '0'
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object errEM: TEdit
    Left = 297
    Top = 272
    Width = 40
    Height = 24
    Hint = 'positive error: pointed above the pole'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 9
    Text = '0'
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object errES: TEdit
    Left = 345
    Top = 272
    Width = 48
    Height = 24
    Hint = 'positive error: pointed above the pole'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 10
    Text = '0.0'
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object errAD: TEdit
    Left = 249
    Top = 240
    Width = 40
    Height = 24
    Hint = 'positive err: pointed east of pole'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 11
    Text = '0'
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object errAM: TEdit
    Left = 297
    Top = 240
    Width = 40
    Height = 24
    Hint = 'positive err: pointed east of pole'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 12
    Text = '0'
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object errAS: TEdit
    Left = 345
    Top = 240
    Width = 48
    Height = 24
    Hint = 'positive err: pointed east of pole'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 13
    Text = '0.0'
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object DTH: TEdit
    Left = 528
    Top = 224
    Width = 41
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 14
    Text = '0'
    Visible = False
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object DTM: TEdit
    Left = 576
    Top = 224
    Width = 41
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 15
    Text = '0'
    Visible = False
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object DTS: TEdit
    Left = 624
    Top = 224
    Width = 41
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 16
    Text = '0.0'
    Visible = False
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object detD: TEdit
    Left = 528
    Top = 256
    Width = 73
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 17
    Text = '0'
    OnExit = NumericOnExit
    OnKeyPress = NumericOnKeyPress
  end
  object DecRatD: TEdit
    Left = 528
    Top = 320
    Width = 73
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 18
    Text = '0'
    Visible = False
    OnExit = test
    OnKeyPress = NumericOnKeyPress
  end
  object RARatD: TEdit
    Left = 528
    Top = 288
    Width = 73
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 19
    Text = '0'
    Visible = False
    OnExit = test
    OnKeyPress = NumericOnKeyPress
  end
  object ObsPanel: TPanel
    Left = 153
    Top = 152
    Width = 248
    Height = 89
    BevelOuter = bvNone
    TabOrder = 3
    OnExit = ObsPanelExit
    object Label31: TLabel
      Left = 108
      Top = 1
      Width = 24
      Height = 17
      Caption = 'deg'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label26: TLabel
      Left = 9
      Top = 57
      Width = 56
      Height = 16
      Caption = 'Dec error'
    end
    object Label23: TLabel
      Left = 9
      Top = 25
      Width = 50
      Height = 16
      Caption = 'RA error'
    end
    object errRD: TEdit
      Left = 96
      Top = 17
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object errRM: TEdit
      Left = 144
      Top = 17
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object errRS: TEdit
      Left = 192
      Top = 17
      Width = 49
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object errDS: TEdit
      Left = 192
      Top = 49
      Width = 49
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object errDM: TEdit
      Left = 144
      Top = 49
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object errDD: TEdit
      Left = 96
      Top = 49
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
  end
  object TestMode: TCheckBox
    Left = 488
    Top = 8
    Width = 97
    Height = 17
    Caption = 'TestMode'
    Checked = True
    State = cbChecked
    TabOrder = 20
    OnClick = TestModeClick
  end
  object LSTPanel: TPanel
    Left = 416
    Top = 185
    Width = 265
    Height = 40
    BevelOuter = bvNone
    TabOrder = 4
    OnExit = LSTPanelExit
    object Label22: TLabel
      Left = 21
      Top = 17
      Width = 84
      Height = 16
      Caption = 'Local Sid time'
    end
    object LSTS: TEdit
      Left = 208
      Top = 9
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = '0.0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object LSTM: TEdit
      Left = 160
      Top = 9
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
    object LSTH: TEdit
      Left = 112
      Top = 9
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnExit = NumericOnExit
      OnKeyPress = NumericOnKeyPress
    end
  end
  object Button4: TButton
    Left = 33
    Top = 320
    Width = 96
    Height = 25
    Caption = 'Swap 1 and 2'
    TabOrder = 21
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 209
    Top = 409
    Width = 73
    Height = 24
    Caption = 'Button5'
    TabOrder = 22
    Visible = False
    OnClick = Button5Click
  end
  object StopBtn: TButton
    Left = 59
    Top = 374
    Width = 92
    Height = 60
    Caption = 'STOP'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 23
  end
  object Edit1: TEdit
    Left = 414
    Top = 404
    Width = 148
    Height = 24
    TabOrder = 24
    Text = 'Edit1'
    Visible = False
    OnExit = Edit1Exit
  end
  object Memo1: TMemo
    Left = 232
    Top = 448
    Width = 401
    Height = 145
    ScrollBars = ssVertical
    TabOrder = 25
  end
  object ApdPort1: TApdWinsockPort
    WsPort = 'telnet'
    Baud = 9600
    ComNumber = 3
    TraceName = 'APRO.TRC'
    LogName = 'APRO1.LOG'
    Open = True
    Left = 640
    Top = 328
  end
  object MainMenu1: TMainMenu
    Left = 656
    Top = 280
    object File1: TMenuItem
      Caption = 'File'
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object Help2: TMenuItem
        Caption = 'Help'
        OnClick = Help2Click
      end
      object About1: TMenuItem
        Caption = 'About'
        OnClick = About1Click
      end
    end
  end
end
