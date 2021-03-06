/* Copyright (c) 2018 The node-webrtc project authors. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be found
 * in the LICENSE.md file in the root of the source tree. All contributing
 * project authors may be found in the AUTHORS file in the root of the source
 * tree.
 */
#include "create-offer-observer.h"

#include "common.h"
#include "peerconnection.h"

using node_webrtc::CreateOfferObserver;
using node_webrtc::PeerConnection;

void CreateOfferObserver::OnSuccess(webrtc::SessionDescriptionInterface* sdp) {
  TRACE_CALL;
  PeerConnection::SdpEvent* data = new PeerConnection::SdpEvent(sdp);
  parent->QueueEvent(PeerConnection::CREATE_OFFER_SUCCESS, static_cast<void*>(data));
  TRACE_END;
}

void CreateOfferObserver::OnFailure(const std::string& msg) {
  TRACE_CALL;
  PeerConnection::ErrorEvent* data = new PeerConnection::ErrorEvent(msg);
  parent->QueueEvent(PeerConnection::CREATE_OFFER_ERROR, static_cast<void*>(data));
  TRACE_END;
}
