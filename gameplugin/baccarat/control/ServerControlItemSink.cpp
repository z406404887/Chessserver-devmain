#include "StdAfx.h"
#include "servercontrolitemsink.h"
#include <locale>
//////////////////////////////////////////////////////////////////////////
//替代结构
struct tagReplaceCard
{
    BYTE							cbCardCount[2];						//扑克数目
    BYTE							cbTableCardArray[2][3];				//桌面扑克
};

//庄对子
tagReplaceCard CardBankerPairCard[] =
{
    3, 3, 0x1b, 0x25, 0x37, 0x01, 0x11, 0x18,
    3, 3, 0x1c, 0x24, 0x37, 0x01, 0x11, 0x14,
    3, 3, 0x25, 0x39, 0x3b, 0x01, 0x11, 0x19,
    3, 3, 0x1c, 0x2b, 0x3a, 0x01, 0x11, 0x18,
    3, 2, 0x1c, 0x25, 0x2a, 0x03, 0x13, 0x00,
    3, 2, 0x34, 0x36, 0x3a, 0x02, 0x22, 0x00,
    3, 2, 0x35, 0x3a, 0x3d, 0x02, 0x12, 0x00,
    3, 2, 0x26, 0x28, 0x31, 0x02, 0x22, 0x00,
    3, 3, 0x22, 0x29, 0x2c, 0x06, 0x16, 0x1c,
    3, 3, 0x35, 0x3b, 0x3c, 0x06, 0x16, 0x32,
    3, 3, 0x2b, 0x34, 0x3a, 0x06, 0x16, 0x1d,
    3, 2, 0x32, 0x33, 0x39, 0x07, 0x17, 0x00,
    3, 3, 0x2c, 0x33, 0x3c, 0x0b, 0x1b, 0x2b,
    3, 3, 0x34, 0x36, 0x3c, 0x0a, 0x2a, 0x2b,
    3, 3, 0x2d, 0x32, 0x3a, 0x0a, 0x1a, 0x23,
    3, 3, 0x2d, 0x34, 0x37, 0x0b, 0x1b, 0x24
};

//庄家代替
tagReplaceCard CardBankerWinCard[] =
{
    2, 3, 0x25, 0x31, 0x00, 0x01, 0x02, 0x04,
    3, 3, 0x09, 0x22, 0x32, 0x01, 0x02, 0x03,
    3, 3, 0x18, 0x23, 0x2c, 0x01, 0x02, 0x0a,
    3, 3, 0x2b, 0x2d, 0x35, 0x01, 0x02, 0x04,
    3, 3, 0x2d, 0x32, 0x39, 0x03, 0x09, 0x13,
    3, 3, 0x1a, 0x24, 0x3d, 0x03, 0x0a, 0x13,
    3, 3, 0x29, 0x32, 0x3c, 0x03, 0x09, 0x13,
    3, 3, 0x2c, 0x32, 0x39, 0x03, 0x0a, 0x12,
    3, 2, 0x21, 0x24, 0x39, 0x06, 0x0c, 0x00,
    3, 2, 0x1b, 0x31, 0x3c, 0x06, 0x0c, 0x00,
    3, 3, 0x1d, 0x2b, 0x36, 0x06, 0x0c, 0x11,
    3, 2, 0x2c, 0x32, 0x3a, 0x06, 0x0b, 0x00,
    3, 2, 0x1b, 0x1d, 0x3b, 0x0b, 0x16, 0x00,
    2, 3, 0x25, 0x31, 0x00, 0x0b, 0x15, 0x22,
    3, 2, 0x23, 0x29, 0x3a, 0x0b, 0x14, 0x00,
    3, 2, 0x25, 0x2d, 0x35, 0x0b, 0x16, 0x00
};

//庄天王
tagReplaceCard CardBankerKingCard[] =
{
    2, 3, 0x25, 0x32, 0x00, 0x01, 0x02, 0x16,
    3, 3, 0x23, 0x2b, 0x39, 0x01, 0x02, 0x06,
    3, 3, 0x15, 0x17, 0x35, 0x01, 0x02, 0x05,
    3, 3, 0x14, 0x16, 0x37, 0x01, 0x02, 0x05,
    2, 2, 0x28, 0x36, 0x00, 0x03, 0x06, 0x00,
    2, 2, 0x2c, 0x34, 0x00, 0x03, 0x06, 0x00,
    2, 2, 0x16, 0x27, 0x00, 0x03, 0x06, 0x00,
    2, 2, 0x14, 0x1a, 0x00, 0x03, 0x06, 0x00,
    2, 3, 0x37, 0x3a, 0x00, 0x07, 0x13, 0x29,
    2, 2, 0x2b, 0x36, 0x00, 0x07, 0x12, 0x00,
    2, 2, 0x28, 0x29, 0x00, 0x07, 0x12, 0x00,
    3, 3, 0x23, 0x2c, 0x39, 0x07, 0x13, 0x18,
    2, 2, 0x1c, 0x24, 0x00, 0x0a, 0x19, 0x00,
    2, 2, 0x34, 0x3b, 0x00, 0x0a, 0x19, 0x00,
    2, 2, 0x25, 0x27, 0x00, 0x0a, 0x19, 0x00,
    2, 2, 0x29, 0x36, 0x00, 0x0a, 0x18, 0x00
};

//平
tagReplaceCard CardEqualCard[] =
{
    2, 2, 0x1d, 0x26, 0x00, 0x01, 0x05, 0x00,
    3, 3, 0x15, 0x1c, 0x29, 0x01, 0x02, 0x11,
    2, 2, 0x15, 0x21, 0x00, 0x01, 0x05, 0x00,
    2, 2, 0x1c, 0x26, 0x00, 0x01, 0x05, 0x00,
    3, 3, 0x1a, 0x25, 0x39, 0x03, 0x0c, 0x11,
    3, 3, 0x21, 0x24, 0x39, 0x03, 0x0c, 0x11,
    3, 3, 0x2a, 0x34, 0x37, 0x03, 0x09, 0x29,
    3, 3, 0x0b, 0x32, 0x3a, 0x03, 0x09, 0x0a,
    2, 2, 0x1c, 0x27, 0x00, 0x06, 0x11, 0x00,
    2, 2, 0x17, 0x1a, 0x00, 0x06, 0x11, 0x00,
    2, 2, 0x21, 0x25, 0x00, 0x06, 0x1c, 0x00,
    2, 2, 0x36, 0x3b, 0x00, 0x06, 0x0c, 0x00,
    3, 3, 0x32, 0x38, 0x3a, 0x0b, 0x1c, 0x1d,
    3, 3, 0x26, 0x27, 0x33, 0x0b, 0x14, 0x22,
    3, 3, 0x14, 0x19, 0x1d, 0x0c, 0x11, 0x12,
    3, 3, 0x2b, 0x2d, 0x34, 0x0b, 0x13, 0x21
};

//同点平
tagReplaceCard CardSamePointCard[] =
{
    2, 2, 0x21, 0x35, 0x00, 0x01, 0x05, 0x00,
    2, 2, 0x22, 0x24, 0x00, 0x02, 0x04, 0x00,
    2, 2, 0x11, 0x15, 0x00, 0x01, 0x05, 0x00,
    2, 2, 0x11, 0x15, 0x00, 0x01, 0x05, 0x00,
    3, 3, 0x23, 0x2b, 0x3a, 0x03, 0x0b, 0x1a,
    2, 2, 0x16, 0x1a, 0x00, 0x06, 0x0a, 0x00,
    3, 3, 0x13, 0x28, 0x39, 0x03, 0x08, 0x09,
    2, 2, 0x26, 0x2c, 0x00, 0x06, 0x0c, 0x00,
    2, 2, 0x29, 0x38, 0x00, 0x09, 0x18, 0x00,
    2, 2, 0x38, 0x39, 0x00, 0x08, 0x09, 0x00,
    3, 3, 0x29, 0x31, 0x32, 0x09, 0x21, 0x22,
    2, 2, 0x38, 0x39, 0x00, 0x08, 0x19, 0x00,
    2, 2, 0x27, 0x2b, 0x00, 0x17, 0x1b, 0x00,
    2, 2, 0x26, 0x2c, 0x00, 0x16, 0x1c, 0x00,
    3, 3, 0x2b, 0x32, 0x35, 0x1b, 0x22, 0x25,
    2, 2, 0x32, 0x35, 0x00, 0x12, 0x15, 0x00
};

//闲对子
tagReplaceCard CardPlayerPairCard[] =
{
    3, 3, 0x05, 0x25, 0x3a, 0x01, 0x02, 0x03,
    2, 2, 0x08, 0x28, 0x00, 0x01, 0x05, 0x00,
    3, 2, 0x07, 0x17, 0x21, 0x01, 0x03, 0x00,
    3, 2, 0x17, 0x27, 0x2d, 0x01, 0x06, 0x00,
    3, 3, 0x25, 0x35, 0x3c, 0x03, 0x09, 0x15,
    3, 3, 0x2a, 0x3a, 0x3d, 0x03, 0x08, 0x14,
    3, 3, 0x1c, 0x2c, 0x34, 0x03, 0x07, 0x12,
    3, 3, 0x21, 0x31, 0x34, 0x03, 0x11, 0x13,
    2, 2, 0x23, 0x33, 0x00, 0x06, 0x0a, 0x00,
    3, 2, 0x1a, 0x2a, 0x32, 0x06, 0x09, 0x00,
    3, 2, 0x17, 0x27, 0x32, 0x05, 0x0d, 0x00,
    3, 2, 0x25, 0x35, 0x3b, 0x06, 0x0a, 0x00,
    2, 3, 0x28, 0x38, 0x00, 0x0b, 0x13, 0x17,
    3, 3, 0x1b, 0x2b, 0x3c, 0x0b, 0x0c, 0x13,
    3, 3, 0x21, 0x31, 0x3b, 0x0a, 0x13, 0x14,
    3, 3, 0x1c, 0x2c, 0x32, 0x0a, 0x0b, 0x0c
};

//闲
tagReplaceCard CardPlayerWinCard[] =
{
    3, 3, 0x09, 0x15, 0x29, 0x01, 0x02, 0x07,
    3, 3, 0x0c, 0x23, 0x2a, 0x01, 0x02, 0x08,
    2, 3, 0x0d, 0x16, 0x00, 0x01, 0x02, 0x07,
    2, 3, 0x11, 0x26, 0x00, 0x01, 0x02, 0x07,
    3, 3, 0x26, 0x27, 0x2a, 0x03, 0x09, 0x0c,
    2, 3, 0x32, 0x34, 0x00, 0x03, 0x08, 0x21,
    3, 3, 0x19, 0x32, 0x36, 0x03, 0x08, 0x15,
    2, 3, 0x17, 0x19, 0x00, 0x03, 0x08, 0x13,
    2, 3, 0x29, 0x38, 0x00, 0x05, 0x18, 0x21,
    3, 3, 0x2b, 0x2c, 0x36, 0x05, 0x1a, 0x1d,
    2, 3, 0x2a, 0x37, 0x00, 0x05, 0x1b, 0x28,
    2, 3, 0x2c, 0x37, 0x00, 0x05, 0x1c, 0x1d,
    3, 3, 0x24, 0x27, 0x36, 0x0b, 0x16, 0x18,
    3, 3, 0x2b, 0x31, 0x36, 0x0b, 0x16, 0x18,
    3, 2, 0x23, 0x32, 0x3d, 0x0b, 0x14, 0x00,
    2, 2, 0x2a, 0x37, 0x00, 0x0b, 0x16, 0x00
};
//闲天王
tagReplaceCard CardPlayerKingCard[] =
{
    2, 2, 0x14, 0x25, 0x00, 0x01, 0x02, 0x00,
    2, 2, 0x14, 0x35, 0x00, 0x01, 0x02, 0x00,
    3, 3, 0x0a, 0x25, 0x34, 0x01, 0x02, 0x03,
    3, 2, 0x28, 0x33, 0x38, 0x01, 0x02, 0x00,
    2, 2, 0x24, 0x35, 0x00, 0x03, 0x09, 0x00,
    2, 2, 0x13, 0x16, 0x00, 0x03, 0x09, 0x00,
    2, 2, 0x18, 0x21, 0x00, 0x03, 0x09, 0x00,
    2, 2, 0x28, 0x2d, 0x00, 0x03, 0x08, 0x00,
    2, 2, 0x19, 0x1b, 0x00, 0x06, 0x09, 0x00,
    2, 2, 0x15, 0x23, 0x00, 0x06, 0x09, 0x00,
    2, 2, 0x19, 0x1a, 0x00, 0x06, 0x09, 0x00,
    2, 2, 0x1a, 0x28, 0x00, 0x06, 0x09, 0x00,
    3, 3, 0x19, 0x22, 0x37, 0x0b, 0x14, 0x16,
    3, 2, 0x1d, 0x21, 0x38, 0x0b, 0x13, 0x00,
    3, 3, 0x34, 0x36, 0x39, 0x0b, 0x13, 0x28,
    2, 2, 0x29, 0x2d, 0x00, 0x0b, 0x13, 0x00
};
//////////////////////////////////////////////////////////////////////////

//
CServerControlItemSink::CServerControlItemSink(void)
{
    //控制变量
    m_cbWinSideControl = 0;
    m_nSendCardCount = 0;
    m_cbExcuteTimes = 0;
}

CServerControlItemSink::~CServerControlItemSink(void)
{

}

//服务器控制
bool __cdecl CServerControlItemSink::ServerControl(WORD wSubCmdID, const void *pDataBuffer, WORD wDataSize, IServerUserItem *pIServerUserItem, ITableFrame *pITableFrame, const tagGameServiceOption *pGameServiceOption)
{
    //如果不具有管理员权限 则返回错误
    if(!CUserRight::IsGameCheatUser(pIServerUserItem->GetUserRight()))
    {
        return false;
    }

    const CMD_C_AdminReq *AdminReq = static_cast<const CMD_C_AdminReq *>(pDataBuffer);
    switch(AdminReq->cbReqType)
    {
    case RQ_RESET_CONTROL:
    {
        m_cbWinSideControl = 0;
        m_cbExcuteTimes = 0;
        CMD_S_CommandResult cResult;
        cResult.cbAckType = ACK_RESET_CONTROL;
        cResult.cbResult = CR_ACCEPT;
        pITableFrame->SendRoomData(pIServerUserItem, SUB_S_AMDIN_COMMAND, &cResult, sizeof(CMD_S_CommandResult));

        //控制信息
        ControlInfo(&cResult, pIServerUserItem, pITableFrame, pGameServiceOption);

        break;
    }
    case RQ_SET_WIN_AREA:
    {
        if(AdminReq->cbExtendData[0] > 0 && AdminReq->cbExtendData[0] <= 8)
        {
            m_cbWinSideControl = AdminReq->cbExtendData[0];
            m_cbExcuteTimes = AdminReq->cbExtendData[1];
            CMD_S_CommandResult cResult;
            cResult.cbAckType = ACK_SET_WIN_AREA;
            cResult.cbResult = CR_ACCEPT;
            pITableFrame->SendRoomData(pIServerUserItem, SUB_S_AMDIN_COMMAND, &cResult, sizeof(CMD_S_CommandResult));

            //控制信息
            ControlInfo(&cResult, pIServerUserItem, pITableFrame, pGameServiceOption);
        }
        else
        {
            CMD_S_CommandResult cResult;
            cResult.cbAckType = ACK_SET_WIN_AREA;
            cResult.cbResult = CR_REFUSAL;
            pITableFrame->SendRoomData(pIServerUserItem, SUB_S_AMDIN_COMMAND, &cResult, sizeof(CMD_S_CommandResult));

            //控制信息
            ControlInfo(&cResult, pIServerUserItem, pITableFrame, pGameServiceOption);
        }
        break;
    }
    case RQ_PRINT_SYN:
    {
        CMD_S_CommandResult cResult;
        cResult.cbAckType = ACK_PRINT_SYN;
        cResult.cbResult = CR_ACCEPT;
        cResult.cbExtendData[0] = m_cbWinSideControl;
        cResult.cbExtendData[1] = m_cbExcuteTimes;
        pITableFrame->SendRoomData(pIServerUserItem, SUB_S_AMDIN_COMMAND, &cResult, sizeof(CMD_S_CommandResult));
        break;

        //控制信息
        ControlInfo(&cResult, pIServerUserItem, pITableFrame, pGameServiceOption);
    }

    }

    return true;
}

//需要控制
bool __cdecl CServerControlItemSink::NeedControl()
{
    if(m_cbWinSideControl > 0 && m_cbWinSideControl <= 8 && m_cbExcuteTimes > 0)
    {
        return true;
    }
    return false;

}

//返回控制区域
bool __cdecl CServerControlItemSink::ControlResult(BYTE	cbTableCardArray[], BYTE cbCardCount[])
{
    switch(m_cbWinSideControl)
    {
    case 1:
    {
        //闲对子
        BYTE cbIndex = rand() % CountArray(CardPlayerPairCard);
        CopyMemory(cbCardCount, CardPlayerPairCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardPlayerPairCard[cbIndex].cbTableCardArray, sizeof(CardPlayerPairCard[cbIndex].cbTableCardArray));
        break;
    }
    case 2:
    {
        //闲
        BYTE cbIndex = rand() % CountArray(CardPlayerWinCard);
        CopyMemory(cbCardCount, CardPlayerWinCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardPlayerWinCard[cbIndex].cbTableCardArray, sizeof(CardPlayerWinCard[cbIndex].cbTableCardArray));
        break;
    }
    case 3:
    {
        //闲天王
        BYTE cbIndex = rand() % CountArray(CardPlayerKingCard);
        CopyMemory(cbCardCount, CardPlayerKingCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardPlayerKingCard[cbIndex].cbTableCardArray, sizeof(CardPlayerKingCard[cbIndex].cbTableCardArray));
        break;
    }
    case 4:
    {
        //平家胜利
        BYTE cbIndex = rand() % CountArray(CardEqualCard);
        CopyMemory(cbCardCount, CardEqualCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardEqualCard[cbIndex].cbTableCardArray, sizeof(CardEqualCard[cbIndex].cbTableCardArray));
        break;
    }
    case 5:
    {
        //同点平
        BYTE cbIndex = rand() % CountArray(CardSamePointCard);
        CopyMemory(cbCardCount, CardSamePointCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardSamePointCard[cbIndex].cbTableCardArray, sizeof(CardSamePointCard[cbIndex].cbTableCardArray));
        break;
    }
    case 6:
    {
        //庄对子
        BYTE cbIndex = rand() % CountArray(CardBankerPairCard);
        CopyMemory(cbCardCount, CardBankerPairCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardBankerPairCard[cbIndex].cbTableCardArray, sizeof(CardBankerPairCard[cbIndex].cbTableCardArray));
        break;
    }
    case 7:
    {
        //庄家胜利
        BYTE cbIndex = rand() % CountArray(CardBankerWinCard);
        CopyMemory(cbCardCount, CardBankerWinCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardBankerWinCard[cbIndex].cbTableCardArray, sizeof(CardBankerWinCard[cbIndex].cbTableCardArray));
        break;
    }
    case 8:
    {
        //庄天王
        BYTE cbIndex = rand() % CountArray(CardBankerKingCard);
        CopyMemory(cbCardCount, CardBankerKingCard[cbIndex].cbCardCount, sizeof(BYTE) * 2);
        CopyMemory(cbTableCardArray, CardBankerKingCard[cbIndex].cbTableCardArray, sizeof(CardBankerKingCard[cbIndex].cbTableCardArray));
        break;
    }
    default:
        ASSERT(FALSE);
        return false;
    }

    m_cbExcuteTimes--;
    return true;
}

//申请结果
VOID CServerControlItemSink::ControlInfo(const void *pBuffer, IServerUserItem *pIServerUserItem, ITableFrame *pITableFrame, const tagGameServiceOption *pGameServiceOption)
{
    const CMD_S_CommandResult *pResult = (CMD_S_CommandResult *)pBuffer;
    CString str;
    switch(pResult->cbAckType)
    {
    case ACK_SET_WIN_AREA:
    {
        if(pResult->cbResult == CR_ACCEPT)
        {
            switch(m_cbWinSideControl)
            {
            case 0:
                str.Format(TEXT("无受控区域"));
                break;
            case 1:
                str.Format(TEXT("执行控制成功,胜利区域:闲对子,执行次数:%d"), m_cbExcuteTimes);
                break;
            case 2:
                str.Format(TEXT("执行控制成功,胜利区域:  闲  ,执行次数:%d"), m_cbExcuteTimes);
                break;
            case 3:
                str.Format(TEXT("执行控制成功,胜利区域:闲天王,执行次数:%d"), m_cbExcuteTimes);
                break;
            case 4:
                str.Format(TEXT("执行控制成功,胜利区域:  平  ,执行次数:%d"), m_cbExcuteTimes);
                break;
            case 5:
                str.Format(TEXT("执行控制成功,胜利区域:同点平,执行次数:%d"), m_cbExcuteTimes);
                break;
            case 6:
                str.Format(TEXT("执行控制成功,胜利区域:庄对子,执行次数:%d"), m_cbExcuteTimes);
                break;
            case 7:
                str.Format(TEXT("执行控制成功,胜利区域:  庄  ,执行次数:%d"), m_cbExcuteTimes);
                break;
            case 8:
                str.Format(TEXT("执行控制成功,胜利区域:庄天王,执行次数:%d"), m_cbExcuteTimes);
                break;
            default:
                break;
            }
        }
        else
        {
            str.Format(TEXT("执行控制失败!"));
        }
        break;
    }
    case ACK_RESET_CONTROL:
    {
        if(pResult->cbResult == CR_ACCEPT)
        {
            str = TEXT("取消控制!");
        }
        break;
    }
    case ACK_PRINT_SYN:
    {
        if(pResult->cbResult == CR_ACCEPT)
        {
            str = TEXT("服务器同步成功!");
        }
        else
        {
            str.Format(TEXT("服务器同步失败!"));
        }
        break;
    }

    default:
        break;
    }

    //记录信息
    CString strControlInfo;
    CTime Time(CTime::GetCurrentTime());
    strControlInfo.Format(TEXT("房间: %s | 桌号: %u | 时间: %d-%d-%d %d:%d:%d\n控制人账号: %s | 控制人ID: %u\n%s\n\n"),
                          pGameServiceOption->szServerName, pITableFrame->GetTableID() + 1, Time.GetYear(), Time.GetMonth(), Time.GetDay(),
                          Time.GetHour(), Time.GetMinute(), Time.GetSecond(), pIServerUserItem->GetNickName(), pIServerUserItem->GetGameID(), str);

    WriteInfo(TEXT("欢乐30秒控制信息.log"), strControlInfo);

    return;
}

//记录信息
VOID CServerControlItemSink::WriteInfo(LPCTSTR pszFileName, LPCTSTR pszString)
{
    //设置语言区域
    char *old_locale = _strdup(setlocale(LC_CTYPE, NULL));
    setlocale(LC_CTYPE, "chs");

    CStdioFile myFile;
    CString strFileName;
    strFileName.Format(TEXT("%s"), pszFileName);
    BOOL bOpen = myFile.Open(strFileName, CFile::modeReadWrite | CFile::modeCreate | CFile::modeNoTruncate);
    if(bOpen)
    {
        myFile.SeekToEnd();
        myFile.WriteString(pszString);
        myFile.Flush();
        myFile.Close();
    }

    //还原区域设定
    setlocale(LC_CTYPE, old_locale);
    free(old_locale);

    return;
}