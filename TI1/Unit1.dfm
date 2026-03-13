object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 654
  ClientWidth = 1071
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  WindowState = wsMaximized
  TextHeight = 15
  object lblKey: TLabel
    Left = 24
    Top = 24
    Width = 57
    Height = 31
    Caption = #1050#1083#1102#1095
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object lblInput: TLabel
    Left = 142
    Top = 168
    Width = 165
    Height = 31
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1090#1077#1082#1089#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object lblOutput: TLabel
    Left = 658
    Top = 168
    Width = 359
    Height = 31
    Caption = #1056#1077#1079#1091#1083#1100#1090#1080#1088#1091#1102#1097#1080#1081' '#1090#1077#1082#1089#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object rgCipher: TRadioGroup
    Left = 344
    Top = 16
    Width = 449
    Height = 113
    Caption = #1040#1083#1075#1086#1088#1080#1090#1084
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      #1042#1080#1078#1077#1085#1077#1088', '#1087#1088#1086#1075#1088#1077#1089#1089#1080#1074#1085#1099#1081' '#1082#1083#1102#1095' (RU)'
      #1057#1090#1086#1083#1073#1094#1086#1074#1099#1081' (EN)')
    ParentFont = False
    TabOrder = 0
  end
  object edtKey: TEdit
    Left = 24
    Top = 61
    Width = 217
    Height = 39
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = #1050#1051#1070#1063
  end
  object memoInput: TMemo
    Left = 32
    Top = 205
    Width = 425
    Height = 236
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    Lines.Strings = (
      'memoInput')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object memoOutput: TMemo
    Left = 586
    Top = 205
    Width = 423
    Height = 236
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    Lines.Strings = (
      'memoOutput')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object btnReadFromFile: TButton
    Left = 34
    Top = 504
    Width = 273
    Height = 41
    Caption = #1055#1056#1054#1063#1048#1058#1040#1058#1068' '#1048#1047' '#1060#1040#1049#1051#1040
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = btnReadFromFileClick
  end
  object btnDecrypt: TButton
    Left = 378
    Top = 568
    Width = 265
    Height = 41
    Caption = #1044#1045#1064#1048#1060#1056#1054#1042#1040#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = btnDecryptClick
  end
  object btnClear: TButton
    Left = 378
    Top = 504
    Width = 265
    Height = 41
    Caption = #1054#1063#1048#1057#1058#1048#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = btnClearClick
  end
  object Button1: TButton
    Left = 34
    Top = 568
    Width = 273
    Height = 41
    Caption = #1064#1048#1060#1056#1054#1042#1040#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = btnEncryptClick
  end
  object btnWriteToFile: TButton
    Left = 696
    Top = 504
    Width = 401
    Height = 41
    Caption = #1056#1045#1047#1059#1051#1068#1058#1048#1056#1059#1070#1065#1048#1049' '#1058#1045#1050#1057#1058' '#1042' '#1060#1040#1049#1051
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = btnWriteToFileClick
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Text files (*.txt)|*.txt|All files (*.*)|*.*'
    Left = 488
    Top = 328
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Text files (*.txt)|*.txt|All files (*.*)|*.*'
    Left = 488
    Top = 392
  end
end
