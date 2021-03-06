.. -*- rst -*-

========
BGP VPNs
========

A new BGPVPN resource is introduced. It contains a set of parameters for a
BGP-based VPN.

A BGPVPN is created by the admin and given to a tenant who can then associate
it to Networks, Routers or Ports (the latter when the ``bgpvpn-routes-control``
extension is available).

The BGP VPNs API lists, shows details for, creates, updates, and deletes
BGP VPNs.

List BGP VPNs
=============

.. rest_method::  GET /v2.0/bgpvpn/bgpvpns

Lists BGP VPNs to which the project has access.

Use the ``fields`` query parameter to control which fields are
returned in the response body. Additionally, you can filter results
by using query string parameters. For information, see `Filtering
and Column Selection <https://wiki.openstack.org/wiki/Neutron/APIv2
-specification#Filtering_and_Column_Selection>`__.

Normal response codes: 200

Error response codes: 400, 401, 403

Request
-------

.. rest_parameters:: parameters.yaml

   - fields: fields

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - bgpvpns: bgpvpns
   - id: bgpvpn-id-body
   - name: bgpvpn-name-required
   - type: bgpvpn-type-required
   - route_distinguishers: bgpvpn-route_distinguishers-required
   - route_targets: bgpvpn-route_targets-required
   - import_targets: bgpvpn-import_targets-required
   - export_targets: bgpvpn-export_targets-required
   - networks: bgpvpn-networks-required
   - routers: bgpvpn-routers-required
   - ports: bgpvpn-ports
   - local_pref: bgpvpn-local_pref
   - vni: bgpvpn-vni-required
   - tenant_id: project_id
   - project_id: project_id

Response Example
----------------

.. literalinclude:: samples/bgpvpn/bgpvpns/bgpvpns-list-response.json
   :language: javascript

Create BGP VPNS
===============

.. rest_method::  POST /v2.0/bgpvpn/bgpvpns

Creates a BGP VPN.

Normal response codes: 201

Error response codes: 400, 401

Request
-------

.. rest_parameters:: parameters.yaml

   - bgpvpn: bgpvpn
   - name: bgpvpn-name
   - route_distinguishers: bgpvpn-route_distinguishers
   - route_targets: bgpvpn-route_targets
   - import_targets: bgpvpn-import_targets
   - export_targets: bgpvpn-export_targets
   - local_pref: bgpvpn-local_pref-request
   - vni: bgpvpn-vni
   - tenant_id: tenant_id-request
   - project_id: project_id-request
   - type: bgpvpn-type

Request Example
---------------

.. literalinclude:: samples/bgpvpn/bgpvpns/bgpvpn-create-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - bgpvpn: bgpvpn
   - id: bgpvpn-id-body
   - name: bgpvpn-name-required
   - type: bgpvpn-type-required
   - route_targets: bgpvpn-route_targets-required
   - import_targets: bgpvpn-import_targets-required
   - export_targets: bgpvpn-export_targets-required
   - networks: bgpvpn-networks-required
   - routers: bgpvpn-routers-required
   - ports: bgpvpn-ports
   - local_pref: bgpvpn-local_pref
   - vni: bgpvpn-vni-required
   - tenant_id: project_id
   - project_id: project_id

Response Example
----------------

.. literalinclude:: samples/bgpvpn/bgpvpns/bgpvpn-create-response.json
   :language: javascript

Show BGP VPN details
====================

.. rest_method::  GET /v2.0/bgpvpn/bgpvpns/{bgpvpn_id}

Shows details for a BGP VPN.

Normal response codes: 200

Error response codes: 401, 403, 404

Request
-------

.. rest_parameters:: parameters.yaml

   - bgpvpn_id: bgpvpn-id-path

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - bgpvpn: bgpvpn
   - id: bgpvpn-id-body
   - name: bgpvpn-name-required
   - type: bgpvpn-type-required
   - route_distinguishers: bgpvpn-route_distinguishers-required
   - route_targets: bgpvpn-route_targets-required
   - import_targets: bgpvpn-import_targets-required
   - export_targets: bgpvpn-export_targets-required
   - networks: bgpvpn-networks-required
   - routers: bgpvpn-routers-required
   - ports: bgpvpn-ports
   - local_pref: bgpvpn-local_pref
   - vni: bgpvpn-vni-required
   - tenant_id: project_id
   - project_id: project_id

Response Example
----------------

.. literalinclude:: samples/bgpvpn/bgpvpns/bgpvpn-show-response.json
   :language: javascript

Update a BGP VPN
================

.. rest_method::  PUT /v2.0/bgpvpn/bgpvpns/{bgpvpn_id}

Updates a BGP VPN.

Normal response codes: 201

Error response codes: 400, 401, 403, 404

Request
-------
A non-admin user can only update the name parameter. All other updates require
admin privileges.

.. rest_parameters:: parameters.yaml

   - bgpvpn_id: bgpvpn-id-path
   - bgpvpn: bgpvpn
   - name: bgpvpn-name
   - route_distinguishers: bgpvpn-route_distinguishers
   - route_targets: bgpvpn-route_targets
   - import_targets: bgpvpn-import_targets
   - export_targets: bgpvpn-export_targets
   - local_pref: bgpvpn-local_pref-request

Request Example
---------------

.. literalinclude:: samples/bgpvpn/bgpvpns/bgpvpn-update-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - bgpvpn: bgpvpn
   - id: bgpvpn-id-body
   - name: bgpvpn-name-required
   - type: bgpvpn-type-required
   - route_distinguishers: bgpvpn-route_distinguishers-required
   - route_targets: bgpvpn-route_targets-required
   - import_targets: bgpvpn-import_targets-required
   - export_targets: bgpvpn-export_targets-required
   - networks: bgpvpn-networks-required
   - routers: bgpvpn-routers-required
   - ports: bgpvpn-ports
   - local_pref: bgpvpn-local_pref
   - vni: bgpvpn-vni-required
   - tenant_id: project_id
   - project_id: project_id

Response Example
----------------

.. literalinclude:: samples/bgpvpn/bgpvpns/bgpvpn-update-response.json
   :language: javascript

Delete BGP VPN
==============

.. rest_method::  DELETE /v2.0/bgpvpn/bgpvpns/{bgpvpn_id}

Deletes a BGP VPN and its network and/or router associations.

Normal response codes: 204

Error response codes: 401, 403, 404

Request
-------

.. rest_parameters:: parameters.yaml

   - bgpvpn_id: bgpvpn-id-path

Response
--------

There is no body content for the response of a successful DELETE request.
