<?php

/**
 * @file
 *   Filters to statuses matching the current context.
 */

/**
 * Filter handler to select statuses from matching the current context.
 */
class facebook_status_views_handler_filter_autotype extends views_handler_filter {
  function query() {
	$this->ensure_my_table();
    $context = facebook_status_determine_context();
    $type = $context['handler']->type();
    $recipient = $context['handler']->find_recipient();
    $recipient_id = $context['handler']->recipient_id($recipient);
    $and = db_and();
	$and->condition("{$this->table_alias}.recipient", $recipient_id);
	$and->condition("{$this->table_alias}.type", $type);
  }
}
