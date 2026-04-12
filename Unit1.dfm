object Form1: TForm1
  Left = 200
  Top = 100
  Caption = 'RSA'
  ClientHeight = 701
  ClientWidth = 704
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 17
  object PanelTop: TPanel
    Left = 0
    Top = 0
    Width = 704
    Height = 48
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitWidth = 702
    object LabelTitle: TLabel
      Left = 12
      Top = 12
      Width = 287
      Height = 17
      Caption = 'RSA '#8212' '#1064#1080#1092#1088#1086#1074#1072#1085#1080#1077' / '#1044#1077#1096#1080#1092#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1092#1072#1081#1083#1072
    end
  end
  object GroupParams: TGroupBox
    Left = 8
    Top = 56
    Width = 340
    Height = 116
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    TabOrder = 1
    object LabelP: TLabel
      Left = 12
      Top = 26
      Width = 72
      Height = 17
      Caption = 'p ('#1087#1088#1086#1089#1090#1086#1077'):'
    end
    object LabelQ: TLabel
      Left = 12
      Top = 58
      Width = 72
      Height = 17
      Caption = 'q ('#1087#1088#1086#1089#1090#1086#1077'):'
    end
    object LabelKs: TLabel
      Left = 12
      Top = 90
      Width = 86
      Height = 17
      Caption = 'K'#1079' ('#1079#1072#1082#1088#1099#1090#1099#1081'):'
    end
    object EditP: TEdit
      Left = 110
      Top = 22
      Width = 80
      Height = 25
      TabOrder = 0
    end
    object EditQ: TEdit
      Left = 110
      Top = 54
      Width = 80
      Height = 25
      TabOrder = 1
    end
    object EditKs: TEdit
      Left = 110
      Top = 86
      Width = 80
      Height = 25
      TabOrder = 2
    end
  end
  object GroupCalc: TGroupBox
    Left = 356
    Top = 56
    Width = 348
    Height = 116
    Caption = #1042#1099#1095#1080#1089#1083#1077#1085#1085#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103
    TabOrder = 2
    object LabelR: TLabel
      Left = 12
      Top = 26
      Width = 46
      Height = 17
      Caption = 'r = p*q:'
    end
    object LabelPhi: TLabel
      Left = 12
      Top = 58
      Width = 25
      Height = 17
      Caption = #1092'(r):'
    end
    object LabelKo: TLabel
      Left = 12
      Top = 90
      Width = 88
      Height = 17
      Caption = 'Ko ('#1086#1090#1082#1088#1099#1090#1099#1081'):'
    end
    object EditR: TEdit
      Left = 110
      Top = 22
      Width = 220
      Height = 25
      ReadOnly = True
      TabOrder = 0
    end
    object EditPhi: TEdit
      Left = 110
      Top = 54
      Width = 220
      Height = 25
      ReadOnly = True
      TabOrder = 1
    end
    object EditKo: TEdit
      Left = 110
      Top = 86
      Width = 220
      Height = 25
      ReadOnly = True
      TabOrder = 2
    end
  end
  object BtnCalcKeys: TButton
    Left = 8
    Top = 180
    Width = 200
    Height = 36
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100' '#1082#1083#1102#1095#1080
    TabOrder = 3
    OnClick = BtnCalcKeysClick
  end
  object GroupFile: TGroupBox
    Left = 8
    Top = 222
    Width = 696
    Height = 99
    TabOrder = 4
    object LabelInputFile: TLabel
      Left = 12
      Top = 26
      Width = 87
      Height = 17
      Caption = #1042#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083':'
    end
    object LabelOutputFile: TLabel
      Left = 12
      Top = 62
      Width = 96
      Height = 17
      Caption = #1042#1099#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083':'
    end
    object EditInputFile: TEdit
      Left = 110
      Top = 22
      Width = 480
      Height = 25
      TabOrder = 0
    end
    object BtnBrowseInput: TButton
      Left = 598
      Top = 22
      Width = 88
      Height = 24
      Caption = #1054#1073#1079#1086#1088'...'
      TabOrder = 1
      OnClick = BtnBrowseInputClick
    end
    object EditOutputFile: TEdit
      Left = 110
      Top = 58
      Width = 480
      Height = 25
      TabOrder = 2
    end
    object BtnBrowseOutput: TButton
      Left = 598
      Top = 58
      Width = 88
      Height = 24
      Caption = #1054#1073#1079#1086#1088'...'
      TabOrder = 3
      OnClick = BtnBrowseOutputClick
    end
  end
  object BtnEncrypt: TButton
    Left = 20
    Top = 340
    Width = 160
    Height = 40
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 5
    OnClick = BtnEncryptClick
  end
  object BtnDecrypt: TButton
    Left = 202
    Top = 340
    Width = 160
    Height = 40
    Caption = #1056#1072#1089#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 6
    OnClick = BtnDecryptClick
  end
  object BtnClear: TButton
    Left = 386
    Top = 340
    Width = 158
    Height = 40
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 7
    OnClick = BtnClearClick
  end
  object MemoLog: TMemo
    Left = 8
    Top = 416
    Width = 688
    Height = 281
    Lines.Strings = (
      'MemoLog')
    TabOrder = 8
  end
  object OpenDialog1: TOpenDialog
    Filter = 'All files (*.*)|*.*'
    Left = 620
    Top = 336
  end
  object SaveDialog1: TSaveDialog
    Filter = 'All files (*.*)|*.*'
    Left = 660
    Top = 336
  end
end
