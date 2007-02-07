// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from 
// be/be_codegen.cpp:910

#include "ControlTaskI.h"
#include "ControlTaskServer.hpp"
#include "ControlTaskProxy.hpp"
#include "CosPropertyServiceI.h"
#include "AttributesI.h"
#include "OperationsI.h"
#include "OperationInterfaceI.h"
#include "ScriptingAccessI.h"
#include "ServicesI.h"
#include "DataFlowI.h"
#include "Method.hpp"


using namespace RTT;
using namespace RTT::Corba;
using namespace CosPropertyService;

// ControlObject:
Orocos_ControlObject_i::Orocos_ControlObject_i (RTT::OperationInterface* orig, PortableServer::POA_ptr the_poa )
    : mobj( orig ), mMFact(), mCFact(), mpoa( PortableServer::POA::_duplicate(the_poa) )
{
}

// Implementation skeleton destructor
Orocos_ControlObject_i::~Orocos_ControlObject_i (void)
{
}

 char* Orocos_ControlObject_i::getName (
      
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      )) 
{
    CORBA::String_var ret = CORBA::string_dup( mobj->getName().c_str() );
    return ret._retn();
}

 char* Orocos_ControlObject_i::getDescription (
      
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      )) 
{
    CORBA::String_var ret = CORBA::string_dup( mobj->getDescription().c_str() );
    return ret._retn();
}

::RTT::Corba::MethodInterface_ptr Orocos_ControlObject_i::methods (
    
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    if ( CORBA::is_nil( mMFact ) ) {
        Logger::log() << Logger::Info << "Creating MethodInterface."<<Logger::endl;
        Orocos_MethodInterface_i* mserv = new Orocos_MethodInterface_i( mobj->methods(), mpoa.in() );
        try {
            mMFact = mserv->_this();
        } catch( ... ) {
            log(Error) << "Failed to create MethodInterface." <<endlog();
        }
    }
    return MethodInterface::_duplicate( mMFact.in() );
}

::RTT::Corba::CommandInterface_ptr Orocos_ControlObject_i::commands (
    
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    if ( CORBA::is_nil( mCFact ) ) {
        try {
            Logger::log() << Logger::Info << "Creating CommandInterface."<<Logger::endl;
            Orocos_CommandInterface_i* mserv = new Orocos_CommandInterface_i( mobj->commands(), mpoa.in() );
            mCFact = mserv->_this();
        } catch( ... ) {
            log(Error) << "Failed to create CommandInterface." <<endlog();
        }
    }
    return ::RTT::Corba::CommandInterface::_duplicate( mCFact.in() );
}



// Implementation skeleton constructor
Orocos_ControlTask_i::Orocos_ControlTask_i (TaskContext* orig, PortableServer::POA_ptr the_poa)
    : Orocos_ControlObject_i(orig, the_poa), mtask( orig ), mCosProps( ), mEEFact()
{
    // Add the corba object to the interface:
    mtask->methods()->addMethod(method("shutdown", &Orocos_ControlTask_i::shutdownCORBA, this),
                                   "Shutdown CORBA ORB. This function makes RunOrb() return.");

}

  void Orocos_ControlTask_i::shutdownCORBA() {
	  ControlTaskServer::ShutdownOrb(false);
  }


// Implementation skeleton destructor
Orocos_ControlTask_i::~Orocos_ControlTask_i (void)
{
}

CORBA::Boolean Orocos_ControlTask_i::start (
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    return mtask->start();
}

CORBA::Boolean Orocos_ControlTask_i::stop (
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    return mtask->stop();
}

CORBA::Boolean Orocos_ControlTask_i::isRunning (
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    return mtask->isRunning();
}


::CosPropertyService::PropertySet_ptr Orocos_ControlTask_i::propertySet (
    
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    // create and activate servant.
    if ( CORBA::is_nil( mCosProps) ) {
        Logger::log() << Logger::Info << "Creating PropertySet."<<Logger::endl;
        CosPropertyService_PropertySet_i* props = new CosPropertyService_PropertySet_i( mtask->attributes()->properties() );
        mCosProps = props->_this();
    }
    return PropertySet::_duplicate( mCosProps.in() );
}

::RTT::Corba::AttributeInterface_ptr Orocos_ControlTask_i::attributes (
    
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    if ( CORBA::is_nil( mAttrs) ) {
        Logger::log() << Logger::Info << "Creating AttributeInterface."<<Logger::endl;
        try {
            Orocos_AttributeInterface_i* attrs = new Orocos_AttributeInterface_i( mtask->attributes(), mpoa.in() );
            mAttrs = attrs->_this();
        } catch( ... ) {
            log(Error) << "Failed to create AttributeInterface." <<endlog();
        }
    }
    return AttributeInterface::_duplicate( mAttrs.in() );
#if 0
    // create and activate servant.
    if ( CORBA::is_nil( mCosAttrs) ) {
        Logger::log() << Logger::Info << "Creating Attributes PropertySet."<<Logger::endl;
        CosPropertyService_PropertySet_i* props = new CosPropertyService_PropertySet_i( mtask->attributes() );
        mCosProps = props->_this();
    }
    return PropertySet::_duplicate( mCosProps.in() );
#endif
}


::RTT::Corba::ScriptingAccess_ptr Orocos_ControlTask_i::scripting (
    
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    if ( CORBA::is_nil( mEEFact ) ) {
        Logger::log() << Logger::Info << "Creating ScriptingAccess."<<Logger::endl;
        Orocos_ScriptingAccess_i* mserv = new Orocos_ScriptingAccess_i( mtask->scripting(), mpoa.in() );
        mEEFact = mserv->_this();
    }
    return ::RTT::Corba::ScriptingAccess::_duplicate( mEEFact.in() );
}

::RTT::Corba::ServiceInterface_ptr Orocos_ControlTask_i::services (
      
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
    if ( CORBA::is_nil( mService ) ) {
        Logger::log() << Logger::Info << "Creating Services."<<Logger::endl;
        RTT_Corba_ServiceInterface_i* mserv = new RTT_Corba_ServiceInterface_i();
        mService = mserv->_this();
    }
    return ::RTT::Corba::ServiceInterface::_duplicate( mService.in() );
}
  
::RTT::Corba::DataFlowInterface_ptr Orocos_ControlTask_i::ports (
      
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
    if ( CORBA::is_nil( mDataFlow ) ) {
        Logger::log() << Logger::Info << "Creating DataFlowInterface."<<Logger::endl;
        RTT_Corba_DataFlowInterface_i* mserv = new RTT_Corba_DataFlowInterface_i( mtask->ports() );
        mDataFlow = mserv->_this();
    }
    return ::RTT::Corba::DataFlowInterface::_duplicate( mDataFlow.in() );
}
  


::RTT::Corba::ControlTask::ControlTaskNames * Orocos_ControlTask_i::getPeerList (
    
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    TaskContext::PeerList peers = mtask->getPeerList();
    ::RTT::Corba::ControlTask::ControlTaskNames_var result = new ::RTT::Corba::ControlTask::ControlTaskNames();
    result->length( peers.size() );
    for (unsigned int i=0; i != peers.size(); ++i )
        result[i] = CORBA::string_dup( peers[i].c_str() );
    
    return result._retn();
}

::RTT::Corba::ControlObject_ptr Orocos_ControlTask_i::getObject (
    const char * name
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    std::string pname(name);
    // detect 'this':
    if ( pname == "this" )
        return this->_this();

    // Cache other objects
    OperationInterface* task = mtask->getObject( pname );
    if ( task ) {
        // do caching....
        Orocos_ControlObject_i* ret;
        if ( ctobjmap[pname] == 0 ) {
            // create or lookup new server for this object.
            ctobjmap[pname] = new Orocos_ControlObject_i(task, mpoa.in() );
        }
        ret = ctobjmap[pname];
        return ret->_this();
    }
    // clear cache if possible.
    ctobjmap.erase( pname );
    return 0;
}


::RTT::Corba::ObjectList * Orocos_ControlTask_i::getObjectList (
    
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    TaskContext::ObjectList objects = mtask->getObjectList();
    ::RTT::Corba::ObjectList_var result = new ::RTT::Corba::ObjectList();
    result->length( objects.size() );
    for (unsigned int i=0; i != objects.size(); ++i )
        result[i] = CORBA::string_dup( objects[i].c_str() );
    
    return result._retn();
}

CORBA::Boolean Orocos_ControlTask_i::hasObject (
    const char * name
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    std::string mname(name);
    return mtask->getObject(mname);
}


::RTT::Corba::ControlTask_ptr Orocos_ControlTask_i::getPeer (
    const char * name
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    std::string pname(name);
    TaskContext* task = mtask->getPeer( pname );
    if ( task ) {
        // create or lookup new server for this peer.
        // do not export it to the naming service.
        return ControlTaskServer::CreateServer( task, false );
    }
    return 0;
}

CORBA::Boolean Orocos_ControlTask_i::addPeer (
    ::RTT::Corba::ControlTask_ptr p,
    const char * alias
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    std::string malias(alias);
    if (mtask->hasPeer(alias) == false )
        return mtask->addPeer( ControlTaskProxy::Create(p), alias );
    return false;
}

CORBA::Boolean Orocos_ControlTask_i::hasPeer (
    const char * name
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    std::string mname(name);
    return mtask->hasPeer(mname);
}

CORBA::Boolean Orocos_ControlTask_i::removePeer (
    const char * name
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    std::string mname(name);
    mtask->removePeer( mname );
    return true;
}

CORBA::Boolean Orocos_ControlTask_i::connectPeers (
    ::RTT::Corba::ControlTask_ptr p
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    TaskContext* t = ControlTaskProxy::Create( p );
    return mtask->connectPeers( t );
}

CORBA::Boolean Orocos_ControlTask_i::disconnectPeers (
    const char * name
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
    std::string pname(name);
    mtask->disconnectPeers( pname );
    return true;
}


