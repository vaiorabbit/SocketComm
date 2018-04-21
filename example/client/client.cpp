#include "SocketComm.h"

int main( int argc, char** argv )
{
    SocketComm::Initialize();

    SocketComm* pClient = SocketComm::CreateClient();
    std::puts( "Client started.");

    int nTiming = 0, nSent = 0 ;
    while ( pClient )
    {
        TNMessagePtr pMsg = pClient->PopReceivedText();
        if ( pMsg != NULL )
        {
            std::printf( "Client got message. : %s", pMsg->Text );
            if ( !std::strcmp(pMsg->Text, "bye\n") )
                break;

            pClient->DeleteReceivedText( pMsg );
        }

        ++nTiming;
        if ( nTiming > 2000000 )
        {
            if ( nSent < 10 )
                pClient->SendText( "Hello, Mr.Server.\n" );
            else
                pClient->SendText( "bye\n" );
            nTiming = 0;
            ++nSent;
        }
    }

    SocketComm::ReleaseNode( pClient );
    std::puts( "Client terminated." );

    SocketComm::Finalize();

    return 0;
}
