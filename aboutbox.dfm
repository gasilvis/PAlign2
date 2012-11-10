object fAbout: TfAbout
  Left = 262
  Top = 216
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  ClientHeight = 301
  ClientWidth = 479
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 16
    Top = 16
    Width = 449
    Height = 225
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvLowered
    TabOrder = 0
    object Image1: TImage
      Left = 24
      Top = 24
      Width = 32
      Height = 32
      AutoSize = True
      Picture.Data = {
        055449636F6E0000010001002020100000000000E80200001600000028000000
        2000000040000000010004000000000080020000000000000000000000000000
        0000000000000000000080000080000000808000800000008000800080800000
        C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
        FFFFFF00CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC00CCCCCCC00CCCC
        CCCCCCCCCCCCCCCCC00CCC0CCC00CCCCCCCCCCCCCCCCCCCCC00C00000C00CCCC
        CCCCCCCCCCCCCCCCC00C00000C00CCCCCCCCCCCCCCCCCCCCC00000000000CCCC
        CCCCCCCCCCCCCCCCC00000000000CCCCCCCCCCCCCCCCCCCCC00C00000C00CCCC
        CCCCCCCCCCCCCCCCCCCC00000CCCCCCCCCCCCCCCCCCCCCCCCCCC00000CCCCCCC
        CCCCCCCCCCCCCCCCCCCC00000CCCCCCCCCCCCCCCCCCCCCCCCCCC00000CCCCCCC
        CCCCCCCCCCCCCCCCCCCC00000CCCCCCCCCCCCCCCCCCCCCCCCCCC00000CCCCCCC
        CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
        CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
        CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCFCCCCCCCCCCCCCCCCC
        CCCCCCCCCCCCCFFFCCCCCCCCCCCCCCCCCCCCCCCCCCCCFFFFFCCCCCCCCCCCCCCC
        CCCCCCCCCCCCCFFFCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCFCCCCCCCCCCCCCCCCC
        CCFCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCFFFCCCCCCCCCCCCCCCCCCCCCCCCCCCC
        FFFFFCCCCCCCCCCCCCCCCCCCCCCCCCCCCFFFCCCCCCCCCCCCCCCCCCCCCCCCCCCC
        CCFCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
        CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
        CCCCCCCC00000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000}
      Stretch = True
    end
    object Label1: TLabel
      Left = 80
      Top = 24
      Width = 106
      Height = 36
      Caption = 'PAlign2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -30
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 80
      Top = 72
      Width = 293
      Height = 20
      Caption = 'The 2 star mounting alignment utility for '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 120
      Top = 96
      Width = 193
      Height = 20
      Caption = 'Meade LX-200 telescopes'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 88
      Top = 136
      Width = 248
      Height = 16
      Alignment = taCenter
      Caption = 'Send complaints, suggestions and kudos '
    end
    object Label5: TLabel
      Left = 96
      Top = 160
      Width = 233
      Height = 16
      Alignment = taCenter
      Caption = 'to George Silvis: PAlign2@GASilvis.net'
    end
  end
  object Button1: TButton
    Left = 174
    Top = 258
    Width = 124
    Height = 31
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Okay'
    TabOrder = 1
    OnClick = Button1Click
  end
end
